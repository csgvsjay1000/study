#include "netlib.h"
#include "BaseSocket.h"
#include "EventDispatch.h"

int netlib_init(){
	int ret = 0;
	return ret;
}

int netlib_listen(
		const char* server_ip,
		uint16_t port,
		callback_t callback,
		void* callback_data){
	CBaseSocket *pSocket = new CBaseSocket();
	pSocket->Listen(server_ip,port,callback,callback_data);
	return 0;
}


int netlib_register_timer(callback_t callback,void* user_data,uint64_t interval){
	

	return 0;
}

void netlib_eventloop(uint32_t wait_timeout){
	CEventDispatch::Instance()->StartDispatch(wait_timeout);
}

int netlib_option(int handle,int opt,void* optval){
	CBaseSocket* pSocket = FindBaseSocket(handle);
	if(!pSocket)
		return -1;
	switch(opt){
		case NETLIB_OPT_SET_CALLBACK:
			pSocket->SetCallback((callback_t)optval);
			break;
		case NETLIB_OPT_SET_CALLBACK_DATA:
			pSocket->SetCallbackData(optval);
			break;
	}
	return 0;
}

int netlib_recv(int handle,void* buf,int len){
	CBaseSocket* pSocket = FindBaseSocket(handle);
	if(!pSocket)
		return -1;
	int ret = pSocket->Recv(buf,len);
	return ret;
}
