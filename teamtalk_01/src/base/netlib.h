#ifndef __NETLIB_H__
#define __NETLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef void (*callback_t)(void* callback_data,uint8_t msg,uint32_t handle,void* pParam);

int netlib_init();

int netlib_listen(
		const char* server_ip,
		uint16_t port,
		callback_t callback,
		void* callback_data);
#endif
