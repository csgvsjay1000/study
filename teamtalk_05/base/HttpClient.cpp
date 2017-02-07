#include "HttpClient.h"

static size_t OnWriteData(void* buffer,size_t size,size_t nmemb,void* lpVoid){
	printf("OnWriteData\n");
}

CURLcode CHttpClient::Get(const string& strUrl,string& strResponse){
	CURLcode res;
	CURL* curl= curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,strUrl.c_str());
	curl_easy_setopt(curl,CURLOPT_READFUNCTION,NULL);
	curl_easy_setopt(curl,CURLOPT_FORBID_REUSE,1);
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,OnWriteData);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,(void*)&strResponse);

	curl_easy_setopt(curl,CURLOPT_NOSIGNAL,1);
	curl_easy_setopt(curl,CURLOPT_CONNECTTIMEOUT,3);
	curl_easy_setopt(curl,CURLOPT_TIMEOUT,3);

	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);

	return res;
}
