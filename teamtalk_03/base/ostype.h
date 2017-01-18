#ifndef __OSTYPE_H__
#define __OSTYPE_H__

#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <netinet/tcp.h>
#include <string.h>

typedef void (*callback_t)(void* callback_data, uint8_t msg, uint32_t handle, void* pParam);

#endif
