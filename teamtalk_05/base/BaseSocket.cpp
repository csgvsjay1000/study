#include "BaseSocket.h"
#include "EventDispatch.h"

typedef hash_map<net_handle_t,CBaseSocket*> SocketMap;
SocketMap g_socket_map;

void AddBaseSocket(CBaseSocket* pSocket){
	g_socket_map.insert(make_pair((net_handle_t)pSocket->GetSocket(),pSocket));
}
CBaseSocket* FindBaseSocket(net_handle_t fd){
	CBaseSocket* pSocket = NULL;
	SocketMap::iterator iter = g_socket_map.find(fd);
	if(iter != g_socket_map.end()){
		pSocket = iter->second;
	}
	return pSocket;
}

void RemoveBaseSocket(CBaseSocket* pSocket){
	g_socket_map.erase((net_handle_t)pSocket->GetSocket());
}

int CBaseSocket::Listen(
		const char* 	server_ip,
		uint16_t 		port,
		callback_t 		callback,
		void* 			callback_data){
	m_local_ip = server_ip;
	m_local_port = port;
	m_callback = callback;
	m_callback_data = callback_data;

	m_socket = socket(AF_INET,SOCK_STREAM,0);

	_SetReuseAddr(m_socket);
	_SetNonblock(m_socket);

	sockaddr_in serv_addr;
	_SetAddr(server_ip,port,&serv_addr);

	int ret = bind(m_socket,(sockaddr*)&serv_addr,sizeof(serv_addr));
	ret = listen(m_socket,64);

	m_state = SOCKET_STATE_LISTENING;
	if(ret >= 0){
		AddBaseSocket(this);
		CEventDispatch::Instance()->AddEvent(m_socket,0);
		printf("CEventDispatch %s\n",m_local_ip.c_str());
	}


	return 0;
}
void CBaseSocket::_SetNonblock(SOCKET fd){
	fcntl(fd,F_SETFL,O_NONBLOCK|fcntl(fd,F_GETFL));
}
void CBaseSocket::_SetReuseAddr(SOCKET fd){
	int reuse = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,(char*)&reuse,sizeof(reuse));
}
void CBaseSocket::_SetAddr(const char* ip,const uint16_t port,sockaddr_in* pAddr){
	memset(pAddr,0,sizeof(sockaddr_in));
	pAddr->sin_family = AF_INET;
	pAddr->sin_port = htons(port);
	pAddr->sin_addr.s_addr = inet_addr(ip);
	if(pAddr->sin_addr.s_addr == INADDR_NONE){
		hostent* host = gethostbyname(ip);
		pAddr->sin_addr.s_addr = *(uint32_t*)host->h_addr;
	}
}

void CBaseSocket::_AcceptNewSocket(){
	SOCKET fd = 0;
	sockaddr_in peer_addr;
	socklen_t addr_len = sizeof(sockaddr_in);
	char ip_str[64];
	while((fd=accept(m_socket,(sockaddr*)&peer_addr,&addr_len))!= -1){
		CBaseSocket* pSocket = new CBaseSocket();
		uint32_t ip = ntohl(peer_addr.sin_addr.s_addr);
		uint16_t port = ntohs(peer_addr.sin_port);

		snprintf(ip_str,sizeof(ip_str),"%d.%d.%d.%d",ip>>24,(ip>>16)&0xFF,(ip>>8)&0xFF,ip&0xFF);
		printf("AcceptNewSocket,socket=%d from %s:%d\n",fd,ip_str,port);

		pSocket->SetSocket(fd);
		pSocket->SetCallback(m_callback);
		pSocket->SetCallbackData(m_callback_data);
		pSocket->SetState(SOCKET_STATE_CONNECTED);
		pSocket->SetRemoteIP(ip_str);
		pSocket->SetRemotePort(port);

		_SetNonblock(fd);
		AddBaseSocket(pSocket);
		CEventDispatch::Instance()->AddEvent(fd,0);
		m_callback(m_callback_data,NETLIB_MSG_CONNECT,(net_handle_t)fd,NULL);
	}
}
void CBaseSocket::OnRead(){
	if(m_state == SOCKET_STATE_LISTENING)
		_AcceptNewSocket();
	else{
		uint64_t avail = 0;
		if((ioctl(m_socket,FIONREAD,&avail)==-1) ||(avail == 0)){
			m_callback(m_callback_data,NETLIB_MSG_CLOSE,(net_handle_t)m_socket,NULL);
		}else
			m_callback(m_callback_data,NETLIB_MSG_READ,(net_handle_t)m_socket,NULL);
		
	}
}
void CBaseSocket::OnWrite(){}
void CBaseSocket::OnClose(){
	vrprintf("OnClose\n");	
	m_state = SOCKET_STATE_CLOSING;
	//m_callback(m_callback_data,NETLIB_MSG_CLOSE,(net_handle_t)m_socket,NULL);
}
int CBaseSocket::Recv(void* buf,int len){
	return recv(m_socket,(char*)buf,len,0);
}
