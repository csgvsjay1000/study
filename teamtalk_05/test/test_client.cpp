#include "netlib.h"
#include "Client.h"

CClient* g_pClient = NULL;

int main(){
	
	string name = "yyy";
	string pass = "123456";

	g_pClient = new CClient(name,pass);
	g_pClient->connect();
	return 0;
}
