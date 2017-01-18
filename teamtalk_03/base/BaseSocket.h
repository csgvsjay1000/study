#ifndef __BASESOCKET__
#define __BASESOCKET__

#include "ostype.h"

using namespace std;

class CBaseSocket{
public:
	CBaseSocket();
	
	int Listen(string& server_ip,uint16_t port,callback_t callback,void* callback_data);
	int Connect(string& server_ip,uint16_t port,callback_t callback,void* callback_data);

private:
	void _SetNonblock(int fd);
	void _SetReuseAddr(int fd);
	void _SetNoDelay(int fd);

	void _SetAddr(const char* ip,uint16_t port,sockaddr_in* pAddr);
	
private:
	int m_socket;
	string m_local_ip;
	uint16_t m_local_port;

	callback_t 		m_callback;
	void* 			m_callback_data;

	uint8_t 		m_state;
};

#endif
