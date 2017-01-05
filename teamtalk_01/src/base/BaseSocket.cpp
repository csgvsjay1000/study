#include "BaseSocket.h"
#include <sys/socket.h>


int CBaseSocket::Listen(const char* server_ip, uint16_t port, callback_t callback, void* callback_data){
	printf("listen\n");
	m_local_ip = server_ip;
	m_local_port = port;

	m_callback_data = callback_data;
	m_callback = callback;

	m_socket = socket(AF_INET,SOCK_STREAM,0);
	if(m_socket == -1){
		return -1;
	}


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

