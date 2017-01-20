#ifndef __CHTTPCLIENT__
#define __CHTTPCLIENT__

#include <string>
#include <curl/curl.h>

using namespace std;

class CHttpClient{
	CURLcode Get(string & strUrl,string & strResponse);
};

#endif
