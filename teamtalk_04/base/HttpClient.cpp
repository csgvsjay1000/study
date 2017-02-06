#include "HttpClient.h"

CURLcode CHttpClient::Get(string& strUrl,string& strResponse){
	CURLcode res;
	CURL* curl = curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,strUrl.c_str());
	
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	return res;
}	
