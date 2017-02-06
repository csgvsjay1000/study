#include "netlib.h"
#include "BaseSocket.h"
#include "EventDispatch.h"

int netlib_listen(string& server_ip,uint16_t port,callback_t callback,void* callback_data){
	CBaseSocket* pSocket = new CBaseSocket();
	int ret = pSocket->Listen(server_ip,port,callback,callback_data);
	return 0;
}

int netlib_register_timer(callback_t callback,void* user_data,uint64_t interval){
	CEventDispatch::Instance()->AddTimer(callback,user_data,interval);
	return 0;
}

void netlib_eventloop(){
	CEventDispatch::Instance()->StartDispatch();
}
