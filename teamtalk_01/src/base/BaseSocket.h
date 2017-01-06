#ifndef __BASESOCKET_H__
#define __BASESOCKET_H__

#include "netlib.h"

enum{
	SOCKET_STATE_IDLE,  			//空闲
	SOCKET_STATE_LISTENING, 			//监听
	SOCKET_STATE_CONNECTING,  			//正在连接
	SOCKET_STATE_CONNECTED, 			//已连接
	SOCKET_STATE_CLOSING			//关闭
};

class CBaseSocket{
	public:
		int GetSocket(){return m_socket;}
		void SetSocket(int fd){m_socket = fd;}
		void SetState(uint8_t state){m_state = state;}
		void SetRemoteIP(char *ip){m_remote_ip = ip;}
		void SetRemotePort(uint16_t port){m_remote_port = port;}
		void SetCallback(callback_t callback){m_callback = callback;}
		void SetCallbackData(void* data){m_callback_data = data;}

	public:
		int Listen(
				const char*charserver_ip, 
				uint16_t port,
				callback_t callback,
				void* callback_data);

	public:
		void OnRead();
		void OnWrite();
		void OnClose();

	private:
		void _SetNonblock(int fd);
		void _SetReuseAddr(int fd);
		void _SetNoDelay(int fd);
		void _SetAddr(const char* ip,const uint16_t port,sockaddr_in *pAddr);			

		void _AcceptNewSocket();
		

	private:
	 	const char *m_local_ip;
		uint16_t m_local_port;
		char *m_remote_ip;
		uint16_t m_remote_port;

		callback_t m_callback;
		void *m_callback_data;

		int m_socket;
		uint8_t m_state;
};

CBaseSocket* FindBaseSocket(int fd);

#endif
