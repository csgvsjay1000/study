#ifndef __TM_CLIENT_H__
#define __TM_CLIENT_H__

#include "netlib.h"
#include "imconn.h"

using namespace std;

class CClient:public CImConn{
public:	

	uint32_t connect(const string & strIp,uint16_t nPort);
	uint32_t login(const string& strName,const string& strPass);
};


#endif
