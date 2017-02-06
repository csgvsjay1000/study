#include "ostype.h"
#include "netlib.h"
#include "HttpConn.h"

using namespace std;


void http_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam){

}

int main(){
	string ip = "192.168.200.85";
	printf("%s\n",ip.c_str());
	uint16_t port = 12135;
	netlib_listen(ip,port,http_callback,NULL);
	init_http_conn();
	netlib_eventloop();

	return 0;
}
