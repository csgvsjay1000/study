#ifndef __CLIENT__
#define __CLIENT__

#include "ostype.h"
#include <string>

using namespace std;

class CClient{
public:
	CClient(const string& strName,const string& strPass);

	void connect();
};

#endif
