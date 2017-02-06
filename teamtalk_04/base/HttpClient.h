#ifndef HTTPCLIENT__
#define HTTPCLIENT__

#include "ostype.h"
#include <curl/curl.h>

using namespace std;

class CHttpClient{

public:
	CURLcode Get(string& strUrl,string& strResponse);	
};

#endif
