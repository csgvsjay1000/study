#ifndef __OSTYPE__
#define __OSTYPE__

#include <stdlib.h>
#include <string>
#include <stdint.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/epoll.h>
#include <netinet/tcp.h>
#include <string.h>

typedef void (*callback_t)(void* callback_data,uint8_t msg,uint32_t handle,void* pParam);

#endif
