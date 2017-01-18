#ifndef __TEST_CLIENT__
#define __TEST_CLIENT__

#include "ostype.h"

using namespace std;

class CClient{
public:
	CClient(const string& strName,const string& strPass,const string strDomain="access");
	~CClient();

	void connect();
};

#endif
