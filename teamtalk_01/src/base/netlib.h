#ifndef __NETLIB_H__
#define __NETLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sys/epoll.h>
#include <ext/hash_map>

#define NETLIB_OPT_SET_CALLBACK 			1
#define NETLIB_OPT_SET_CALLBACK_DATA 		2
#define NETLIB_OPT_GET_REMOTE_IP			3
#define NETLIB_OPT_GET_REMOTE_PORT 			4
#define NETLIB_OPT_GET_LOCAL_IP 			5
#define NETLIB_OPT_GET_LOCAL_PORT			6
#define NETLIB_OPT_SET_SEND_BUF_SIZE 		7
#define NETLIB_OPT_SET_RECV_BUF_SIZE 		8


enum{
	NETLIB_MSG_CONNECT = 1,
	NETLIB_MSG_CONFIRM,
	NETLIB_MSG_READ,
	NETLIB_MSG_WRITE,
	NETLIB_MSG_CLOSE,
	NETLIB_MSG_TIMER,
	NETLIB_MSG_LOOP,
};

typedef void (*callback_t)(void* callback_data,uint8_t msg,uint32_t handle,void* pParam);

int netlib_init();

int netlib_listen(
		const char* server_ip,
		uint16_t port,
		callback_t callback,
		void* callback_data);

int netlib_register_timer(callback_t callback,void* user_data,uint64_t interval);

void netlib_eventloop(uint32_t wait_timeout = 100);

int netlib_option(int handle,int opt,void* optval);

int netlib_recv(int handle,void* buf,int len);

#define  vrprintf(fmt, ...) {printf(("%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}

using namespace __gnu_cxx;
using namespace std;

#endif
