#include "Client.h"
#include "HttpClient.h"

CClient::CClient(const string& strName,const string& strPass){

}

void CClient::connect(){
	CHttpClient httpClient;
	string strUrl = "http://127.0.0.1:8080/msg_server";
	string strResp;
	CURLcode nRet = httpClient.Get(strUrl,strResp);
	printf("connect\n");
}
