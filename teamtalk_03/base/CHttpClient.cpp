#include "CHttpClient.h"


CURLcode CHttpClient::Get(string & strUrl,string & strResponse){
	CURLcode res;
	CURL* curl = curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,strUrl.c_str());
	curl_easy_setopt(curl,CURLOPT_READFUNCTION,NULL);
	
}
