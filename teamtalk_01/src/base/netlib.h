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

typedef void (*callback_t)(void* callback_data,uint8_t msg,uint32_t handle,void* pParam);

int netlib_init();

int netlib_listen(
		const char* server_ip,
		uint16_t port,
		callback_t callback,
		void* callback_data);

int netlib_register_timer(callback_t callback,void* user_data,uint64_t interval);

#endif
