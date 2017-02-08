#ifndef __LOGINCONN__
#define __LOGINCONN__

#include "netlib.h"

typedef struct {
	string 		ip_addr1; 	
	string 		ip_addr2;
	uint16_t 	port;
	uint32_t  	max_conn_cnt;
	uint32_t 	cur_conn_cnt;
	string 		hostname;
}msg_serv_info_t;

#endif
