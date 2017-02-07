#ifndef __OSTYPE__
#define __OSTYPE__

#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <signal.h>

#include <stdexcept>
#include <ext/hash_map>

using namespace __gnu_cxx;

typedef int SOCKET;


typedef int 		net_handle_t;

enum{
	NETLIB_OK 		= 0,
	NETLIB_ERROR 	= -1
};

enum {
	NETLIB_MSG_CONNECT =1,
	NETLIB_MSG_CONFIRM,
	NETLIB_MSG_READ,
	NETLIB_MSG_WRITE,
	NETLIB_MSG_CLOSE,
	NETLIB_MSG_TIMER,
	NETLIB_MSG_LOOP
};

typedef void (*callback_t)(void* callback_data,uint8_t msg,uint32_t handle,void* pParam);

#endif
