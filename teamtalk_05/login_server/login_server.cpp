#include "netlib.h"

void http_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam){

}

int main(int argc,char* argv[]){

	char* http_listen_ip = "0.0.0.0";
	char* str_http_port = "8080";

	uint16_t http_port = atoi(str_http_port);
	
	netlib_listen(http_listen_ip,http_port,http_callback,NULL);

}
