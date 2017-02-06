#include "HttpConn.h"

void http_conn_timer_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam){
}
void init_http_conn(){
	netlib_register_timer(http_conn_timer_callback,NULL,100); 
}
