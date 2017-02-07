#ifndef __HTTPCLIENT__
#define __HTTPCLIENT__

#include "ostype.h"
#include <curl/curl.h>
#include <string>

using namespace std;

class CHttpClient{
public:
	CURLcode Get(const string& strUrl,string& strResponse);
};
	
#endif
