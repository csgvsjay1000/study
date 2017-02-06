#include "BaseSocket.h"
#include "EventDispatch.h"

CBaseSocket::CBaseSocket(){

}

int CBaseSocket::Listen(string& server_ip,uint16_t port,callback_t callback,void* callback_data){
	m_local_ip = server_ip;
	m_local_port = port;
	m_callback = callback;
	m_callback_data = callback_data;

	m_socket = socket(AF_INET,SOCK_STREAM,0);
	
	_SetReuseAddr(m_socket);
	_SetNonblock(m_socket);

	sockaddr_in serv_addr;
	_SetAddr(server_ip.c_str(),port,&serv_addr);
	int ret = bind(m_socket, (sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret == -1)
		close(m_socket);
	ret = listen(m_socket,64);

	printf("m_local_ip:%s\n",m_local_ip.c_str());
	CEventDispatch::Instance()->AddEvent(m_socket,0);
	return 0;
}
int CBaseSocket::Connect(string& server_ip,uint16_t port,callback_t callback,void* callback_data){
	m_remote_ip = server_ip;
	m_remote_port = port;
	m_callback = callback;
	m_callback_data = callback_data;

	m_socket = socket(AF_INET,SOCK_STREAM,0);
	
	//_SetReuseAddr(m_socket);
	_SetNonblock(m_socket);

	sockaddr_in serv_addr;
	_SetAddr(server_ip.c_str(),port,&serv_addr);
	connect(m_socket,(sockaddr*)&serv_addr,sizeof(serv_addr));
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
	int nodelay = 1;
	setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (char*)&nodelay, sizeof(nodelay));
}

void CBaseSocket::_SetAddr(const char* ip,uint16_t port,sockaddr_in* pAddr){
	memset(pAddr, 0, sizeof(sockaddr_in));
	pAddr->sin_family = AF_INET;
	pAddr->sin_port = htons(port);
	pAddr->sin_addr.s_addr = inet_addr(ip);
	if (pAddr->sin_addr.s_addr == INADDR_NONE){
		hostent* host = gethostbyname(ip);
		if (host == NULL)
			return;
		pAddr->sin_addr.s_addr = *(uint32_t*)host->h_addr;
	}
}

