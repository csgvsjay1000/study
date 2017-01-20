#ifndef __NETLIB__
#define __NETLIB__

#include "ostype.h"

using namespace std;

int netlib_listen(
		string& server_ip, 
		uint16_t port,
		callback_t callback,
		void* callback_data
		);

void netlib_eventloop();

#endif
