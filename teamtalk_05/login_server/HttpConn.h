#ifndef __HTTPCONN__
#define __HTTPCONN__

#include "netlib.h"
#include "UtilPdu.h"
#include "HttpParserWrapper.h"

#define READ_BUF_SIZE 	2048

class CHttpConn{
public:
	CHttpConn();
	void OnConnect(net_handle_t handle);

	void Close();
	void OnClose();
	void OnTimer();

	void OnRead();

private:
	void _HandleMsgServRequest(string& url,string& post_data);
private:
	net_handle_t 	m_socket_handle;
	uint32_t 		m_conn_handle;
	uint64_t 		m_last_recv_tick;

	CSimpleBuffer 	m_in_buf;
	CHttpParserWrapper 	m_cHttpParser;	
};

typedef hash_map<uint32_t,CHttpConn*> HttpConnMap_t;

CHttpConn* FindHttpConnByHandle(uint32_t handle);

void init_http_conn();

#endif
