#ifndef __BASESOCKET_H__
#define __BASESOCKET_H__

#include "netlib.h"

class CBaseSocket{
	public:
		int Listen(
				const char*charserver_ip, 
				uint16_t port,
				callback_t callback,
				void* callback_data);
	private:
		void _SetNonblock(int fd);
		void _SetReuseAddr(int fd);
		void _SetNoDelay(int fd);
			

	private:
	 	const char *m_local_ip;
		uint16_t m_local_port;

		callback_t m_callback;
		void *m_callback_data;

		int m_socket;
};

#endif
