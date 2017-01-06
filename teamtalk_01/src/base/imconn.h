#ifndef __IMCONN_H__
#define __IMCONN_H__

#include "netlib.h"

class CImConn{
public:

};

typedef hash_map<int,CImConn*> ConnMap_t;
typedef hash_map<uint32_t,CImConn*> UserMap_t;

void imconn_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam);

#endif
