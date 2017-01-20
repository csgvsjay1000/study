#include "ostype.h"
#include "netlib.h"

using namespace std;

void http_callback(void* callback_data, uint8_t msg, uint32_t handle, void* pParam){

}

int main(){

	string ip = "192.168.200.85";
	printf("%s\n",ip.c_str());
	uint16_t http_port = 12135;
	netlib_listen(ip, http_port, http_callback, NULL);
	netlib_eventloop();
	return 0;
}
