#include "ostype.h"
#include "netlib.h"

using namespace std;

void http_callback(void* callback_data, uint8_t msg, uint32_t handle, void* pParam){

}

int main(){

	string ip = "0.0.0.0";
	printf("%s\n",ip.c_str());
	uint16_t http_port = 8090;
	netlib_listen(ip, http_port, http_callback, NULL);

	return 0;
}
