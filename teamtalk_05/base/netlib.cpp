#include "netlib.h"
#include "BaseSocket.h"

int netlib_init(){
	int ret = NETLIB_OK;
	return ret;
}

int netlib_destory(){

}

int netlib_listen(
		const char* server_ip,
		uint16_t 	port,
		callback_t 	callback,
		void* 		callback_data
		){
	CBaseSocket* pSocket = new CBaseSocket();
	int ret = pSocket->Listen(server_ip,port,callback,callback_data);

	return ret;
}
