#ifndef __IMCONN_H__
#define __IMCONN_H__

#include "netlib.h"
#include "UtilPdu.h"

#define READ_BUF_SIZE 2048

class CImConn{
public:
	virtual void OnRead();

protected:
	int m_handle;
	CSimpleBuffer m_in_buf;
	CSimpleBuffer m_out_buf;
	
};

typedef hash_map<int,CImConn*> ConnMap_t;
typedef hash_map<uint32_t,CImConn*> UserMap_t;

void imconn_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam);

#endif
