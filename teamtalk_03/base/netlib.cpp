#include "netlib.h"
#include "BaseSocket.h"

using namespace std;

int netlib_listen(
		string& server_ip, 
		uint16_t port,
		callback_t callback,
		void* callback_data
		){
	printf("netlib_listen() called\n");
	CBaseSocket* pSocket = new CBaseSocket;
	pSocket->Listen(server_ip,port,callback,callback_data);
	
	return 0;
}
