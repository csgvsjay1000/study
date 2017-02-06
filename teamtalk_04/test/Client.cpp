#include "Client.h"
#include "HttpClient.h"

CClient::CClient(string& strName,string& strPass,string strDomain):
	m_strName(strName),m_strPass(strPass),m_strLoginDomain(strDomain){

}

void CClient::connect(){
	CHttpClient httpClient;
	string strUrl = m_strLoginDomain;
	string strResp;
	CURLcode nRet = httpClient.Get(strUrl,strResp);

}

uint32_t CClient::login(string& strName,string& strPass){

}
