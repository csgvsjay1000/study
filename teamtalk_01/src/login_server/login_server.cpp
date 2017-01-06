#include <stdio.h>
#include "netlib.h"
#include "LoginConn.h"

void client_callback(void *callback_data,uint8_t msg,uint32_t handle, void *pParam){
	vrprintf("callback\n");
	if(msg == NETLIB_MSG_CONNECT){
		CLoginConn* pConn = new CLoginConn();
		pConn->OnConnect2(handle,0);
	}
}

int main(){
	printf("main\n");
	netlib_init();
	char *client_ip = "192.168.200.85";
	uint16_t client_port = 12345;
	netlib_listen(client_ip,client_port,client_callback,NULL);
	
	netlib_eventloop();

	return 0;
}
