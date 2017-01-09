#include "BaseSocket.h"
#include "EventDispatch.h"



typedef hash_map<int,CBaseSocket*> SocketMap;
SocketMap g_socket_map;

void AddBaseSocket(CBaseSocket* pSocket){
	g_socket_map.insert(make_pair(pSocket->GetSocket(),pSocket));
}

CBaseSocket* FindBaseSocket(int fd){
	CBaseSocket* pSocket = NULL;
	SocketMap::iterator iter = g_socket_map.find(fd);
	if(iter != g_socket_map.end()){
		pSocket = iter->second;
	}
	return pSocket;
}

int CBaseSocket::Listen(const char* server_ip, uint16_t port, callback_t callback, void* callback_data){
	m_local_ip = server_ip;
	m_local_port = port;

	m_callback_data = callback_data;
	m_callback = callback;

	m_socket = socket(AF_INET,SOCK_STREAM,0);
	if(m_socket == -1){
		return -1;
	}
	_SetReuseAddr(m_socket);
	_SetNonblock(m_socket);

	sockaddr_in serv_addr;
	_SetAddr(server_ip,port,&serv_addr);
	int ret = bind(m_socket,(sockaddr *)&serv_addr,sizeof(serv_addr));
	if(ret < 0){
		return -1;
	}
	ret = listen(m_socket,64);
	if(ret < 0){
		return -1;
	}
	m_state = SOCKET_STATE_LISTENING;
	AddBaseSocket(this);
	CEventDispatch::Instance()->AddEvent(m_socket,0);
	
	return 0;
}


void CBaseSocket::_SetNonblock(int fd){
	fcntl(fd, F_SETFL, O_NONBLOCK | fcntl(fd, F_GETFL));
}
void CBaseSocket::_SetReuseAddr(int fd){
	int reuse = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(reuse));
}
void CBaseSocket::_SetNoDelay(int fd){

}


void CBaseSocket::_SetAddr(const char* ip,const uint16_t port,sockaddr_in *pAddr){
	memset(pAddr,0,sizeof(sockaddr_in));
	pAddr->sin_family = AF_INET;
	pAddr->sin_port = htons(port);
	pAddr->sin_addr.s_addr = inet_addr(ip);
	if(pAddr->sin_addr.s_addr == INADDR_NONE){
		hostent* host = gethostbyname(ip);
		if(host == NULL){
			return;
		}
		pAddr->sin_addr.s_addr = *(uint32_t*)host->h_addr;
	}
}	

void CBaseSocket::_AcceptNewSocket(){
	int fd = 0;
	sockaddr_in peer_addr;
	socklen_t addr_len = sizeof(sockaddr_in);
	char ip_str[64];
	while((fd = accept(m_socket,(sockaddr *)&peer_addr,&addr_len)) != -1){
		CBaseSocket* pSocket = new CBaseSocket();
		uint32_t ip = ntohl(peer_addr.sin_addr.s_addr);
		uint16_t port = ntohl(peer_addr.sin_port);
		snprintf(ip_str, sizeof(ip_str), "%d.%d.%d.%d", ip >> 24, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
		vrprintf("AcceptNewSocket, socket=%d from %s:%d\n", fd, ip_str, port);
		pSocket->SetSocket(fd);
		pSocket->SetState(SOCKET_STATE_CONNECTED);
		pSocket->SetRemoteIP(ip_str);
		pSocket->SetRemotePort(port);
		pSocket->SetCallback(m_callback);
		pSocket->SetCallbackData(m_callback_data);
		_SetNonblock(fd);
		AddBaseSocket(pSocket);
		CEventDispatch::Instance()->AddEvent(fd,0);
		m_callback(m_callback_data,NETLIB_MSG_CONNECT,fd,NULL);
	}

}
void CBaseSocket::OnRead(){
	if(m_state == SOCKET_STATE_LISTENING){
		_AcceptNewSocket();
		return;
	}
	m_callback(m_callback_data,NETLIB_MSG_READ,m_socket,NULL);
}
void CBaseSocket::OnWrite(){

}
void CBaseSocket::OnClose(){

}
int CBaseSocket::Send(void* buf,int len){
	int ret = send(m_socket,(char*)buf,len,0);
	return ret;
}

int CBaseSocket::Recv(void* buf,int len){
	return recv(m_socket,(char*)buf,len,0);
}
int CBaseSocket::Close(){
	return 0;
}
