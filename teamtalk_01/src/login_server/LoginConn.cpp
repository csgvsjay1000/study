#include "LoginConn.h"

static ConnMap_t g_client_conn_map;

void CLoginConn::OnConnect2(int handle,int conn_type){
	ConnMap_t* conn_map = &g_client_conn_map;
	conn_map->insert(make_pair(handle,this));
	netlib_option(handle,NETLIB_OPT_SET_CALLBACK,(void*)imconn_callback);
	netlib_option(handle,NETLIB_OPT_SET_CALLBACK_DATA,(void*)conn_map);
}
