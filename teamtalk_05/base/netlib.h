#ifndef __NETLIB__
#define __NETLIB__

#include "ostype.h"

#define NETLIB_OPT_SET_CALLBACK 		1
#define NETLIB_OPT_SET_CALLBACK_DATA	1
#define NETLIB_OPT_GET_REMOTE_IP 		1
#define NETLIB_OPT_GET_REMOTE_PORT		1
#define NETLIB_OPT_GET_LOCAL_IP 		1
#define NETLIB_OPT_GET_LOCAL_PORT 		1
#define NETLIB_OPT_SET_SEND_BUF_SIZE	1
#define NETLIB_OPT_SET_RECV_BUF_SIZE	1

#define NETLIB_MAX_SOCKET_BUF_SIZE 		(128*1024)

int netlib_init();

int netlib_destory();

int netlib_listen(
		const char* server_ip,
		uint16_t 	port,
		callback_t 	callback,
		void* 		callback_data
		);


#endif
