#ifndef __CLIENT__
#define __CLIENT__

#include <iostream>
#include "ostype.h"

using namespace std;

class CClient{

public:
	CClient(string& strName,string& strPass,string strDomain="http://192.168.200.85:12138");
public:
	void connect();
	uint32_t login(string& strName,string& strPass);

private:
	string 		m_strName;
	string 		m_strPass;
	string 		m_strLoginDomain;
};

#endif
