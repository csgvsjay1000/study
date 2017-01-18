#include "Client.h"

using namespace std;

CClient::CClient(const string& strName,const string& strPass,const string strDomain){
	printf("CClient() called\n");
}
CClient::~CClient(){
	printf("~CClient() called\n");
}

void CClient::connect(){
	printf("connect() called\n");
}
