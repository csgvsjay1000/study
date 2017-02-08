#include "netlib.h"
#include "HttpConn.h"

void http_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam){
	vrprintf("http_callback\n");
	if(msg == NETLIB_MSG_CONNECT){
		CHttpConn* pConn = new CHttpConn();
		pConn->OnConnect(handle);
	}
}
void msg_serv_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam){
	vrprintf("msg_serv_callback\n");
	if(msg == NETLIB_MSG_CONNECT){
	
	}
}

int main(int argc,char* argv[]){

	// http 监听接口
	char* http_listen_ip = "0.0.0.0";
	char* str_http_port = "8080";
	
	// msg_server监听本地接口
	char* msg_server_listen_ip = "0.0.0.0";
	char* str_msg_server_port = "8100";

	uint16_t http_port = atoi(str_http_port);
	uint16_t msg_server_port = atoi(str_msg_server_port);
	
	netlib_listen(http_listen_ip,http_port,http_callback,NULL);
	
	netlib_listen(msg_server_listen_ip,msg_server_port,msg_serv_callback,NULL);
	
	netlib_eventloop();
}
