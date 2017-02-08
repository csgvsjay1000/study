#include "HttpConn.h"
#include "util.h"
#include "LoginConn.h"

static HttpConnMap_t g_http_conn_map;
static uint32_t g_conn_handle_generator = 0;

extern map<uint32_t,msg_serv_info_t*> 	g_msg_serv_info;

CHttpConn* FindHttpConnByHandle(uint32_t conn_handle){
	CHttpConn* pConn = NULL;
	HttpConnMap_t::iterator it = g_http_conn_map.find(conn_handle);
	if(it != g_http_conn_map.end())
		pConn = it->second;
	return pConn;
}

void httpconn_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam){
	uint32_t conn_handle =*((uint32_t*)(&callback_data));
	CHttpConn* pConn = FindHttpConnByHandle(conn_handle);
	if(!pConn)
		return;
	vrprintf("httpconn_callback\n");
	
	switch(msg){
	case NETLIB_MSG_READ:
		vrprintf("read\n");
		pConn->OnRead();
		break;
	case NETLIB_MSG_CLOSE:
		vrprintf("close\n");
		break;
	}
}
void http_conn_timer_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam){
	
}
void init_http_conn(){
 	netlib_register_timer(http_conn_timer_callback,NULL,1000);
}

CHttpConn::CHttpConn(){
	m_conn_handle = ++g_conn_handle_generator;	
}

void CHttpConn::OnConnect(net_handle_t handle){
	vrprintf("OnConnect,handle=%d\n",handle);
	m_socket_handle = handle;
	g_http_conn_map.insert(make_pair(m_conn_handle,this));
	
	netlib_option(handle,NETLIB_OPT_SET_CALLBACK,(void*)httpconn_callback);
	netlib_option(handle,NETLIB_OPT_SET_CALLBACK_DATA,(void*)m_conn_handle);

}

void CHttpConn::Close(){}
void CHttpConn::OnClose(){}
void CHttpConn::OnTimer(){}
void CHttpConn::OnRead(){
	for(;;){
		uint32_t free_buf_len = m_in_buf.GetAllocSize() - m_in_buf.GetWriteOffset();
		if(free_buf_len < READ_BUF_SIZE + 1)
			m_in_buf.Extend(READ_BUF_SIZE + 1);
		int ret = netlib_recv(m_socket_handle,m_in_buf.GetBuffer()+m_in_buf.GetWriteOffset(),READ_BUF_SIZE);
		if(ret<=0)
			break;
		m_in_buf.IncWriteOffset(ret);
		m_last_recv_tick = get_tick_count();

	}
	char* in_buf = (char*)m_in_buf.GetBuffer();
	uint32_t buf_len = m_in_buf.GetWriteOffset();
	in_buf[buf_len] = '\0';

	m_cHttpParser.ParseHttpContent(in_buf,buf_len);
	if(m_cHttpParser.IsReadAll()){
		string url = m_cHttpParser.GetUrl();
		if(strncmp(url.c_str(),"/msg_server",11)==0){
			string content = m_cHttpParser.GetBodyContent();

		}
		vrprintf("url: %s\n",url.c_str());
	}

}
void CHttpConn::_HandleMsgServRequest(string& url,string& post_data){

}
