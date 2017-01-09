#ifndef __LOGIN_CONN_H__
#define __LOGIN_CONN_H__

#include "imconn.h"

class CLoginConn : public CImConn{
public:
	void OnConnect2(int handle,int conn_type);

};



#endif
