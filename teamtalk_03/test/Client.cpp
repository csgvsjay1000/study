#include "Client.h"
#include "BaseSocket.h"

using namespace std;

CClient::CClient(const string& strName,const string& strPass,const string strDomain){
	printf("CClient() called\n");
}
CClient::~CClient(){
	printf("~CClient() called\n");
}

void CClient::connect(){
	printf("connect() called\n");
	CBaseSocket* pSocket = new CBaseSocket();
	string ip = "192.168.200.85";
	uint16_t port = 12135;
	pSocket->Connect(ip,port,NULL,NULL);
}
