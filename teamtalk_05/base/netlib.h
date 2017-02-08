#ifndef __NETLIB__
#define __NETLIB__

#include "ostype.h"

#define NETLIB_OPT_SET_CALLBACK 		1
#define NETLIB_OPT_SET_CALLBACK_DATA	2
#define NETLIB_OPT_GET_REMOTE_IP 		3
#define NETLIB_OPT_GET_REMOTE_PORT		4
#define NETLIB_OPT_GET_LOCAL_IP 		5
#define NETLIB_OPT_GET_LOCAL_PORT 		6
#define NETLIB_OPT_SET_SEND_BUF_SIZE	7
#define NETLIB_OPT_SET_RECV_BUF_SIZE	8

#define NETLIB_MAX_SOCKET_BUF_SIZE 		(128*1024)

int netlib_init();

int netlib_destory();

int netlib_listen(
		const char* server_ip,
		uint16_t 	port,
		callback_t 	callback,
		void* 		callback_data
		);
void netlib_eventloop();

int netlib_register_timer(callback_t callback,void* user_data,uint64_t interval);

int netlib_option(net_handle_t handle,int opt,void* optval);

int netlib_recv(net_handle_t handle,void* buf,int len);

#endif
