#include "netlib.h"
#include "BaseSocket.h"

int netlib_init(){
	int ret = 0;
	printf("helloworld\n");
	return ret;
}

int netlib_listen(
		const char* server_ip,
		uint16_t port,
		callback_t callback,
		void* callback_data){
	printf("listen\n");
	CBaseSocket *pSocket = new CBaseSocket();
	pSocket->Listen(server_ip,port,callback,callback_data);
	return 0;
}


int netlib_register_timer(callback_t callback,void* user_data,uint64_t interval){
	

	return 0;
}
