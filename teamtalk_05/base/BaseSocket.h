#ifndef __SOCKET__
#define __SOCKET__

#include "ostype.h"
#include "util.h"

enum{
	SOCKET_STATE_IDLE,
	SOCKET_STATE_LISTENING,
	SOCKET_STATE_CONNECTING,
	SOCKET_STATE_CONNECTED,
	SOCKET_STATE_CLOSING
};

class CBaseSocket : public CRefObject{

public:
	SOCKET GetSocket(){return m_socket;}
	void SetSocket(SOCKET fd){m_socket = fd;}
	void SetState(uint8_t state){m_state = state;}

	void SetCallback(callback_t callback){m_callback = callback;}
	void SetCallbackData(void* data){m_callback_data = data;}
	void SetRemoteIP(char* ip){m_remote_ip=ip;}
	void SetRemotePort(uint16_t port){m_remote_port=port;}

public:
	int Listen(
			const char* 	server_ip,
			uint16_t 		port,
			callback_t 		callback,
			void* 			callback_data
			);
	int Recv(void* buf,int len);

public:
	void OnRead();
	void OnWrite();
	void OnClose();

private:
	void _SetNonblock(SOCKET fd);
	void _SetReuseAddr(SOCKET fd);
	void _SetAddr(const char* ip,const uint16_t port,sockaddr_in* pAddr);

	void _AcceptNewSocket();

private:
	string 			m_remote_ip;
	uint16_t 		m_remote_port;
	string 			m_local_ip;
	uint16_t 		m_local_port;

	callback_t 		m_callback;
	void* 			m_callback_data;
	
	uint8_t 		m_state;
	SOCKET 			m_socket;

};

CBaseSocket* FindBaseSocket(net_handle_t fd);

#endif
