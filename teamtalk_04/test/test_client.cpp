#include "ostype.h"
#include "Client.h"

using namespace std;

int main(){
	string name = "yyy";
	string pass = "123456";
	CClient* g_pClient = new CClient(name,pass);
	g_pClient->connect();
	return 0;
}
