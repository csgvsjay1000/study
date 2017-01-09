#include "imconn.h"

static CImConn* FindImConn(ConnMap_t* imconn_map,int handle){
	CImConn* pConn = NULL;
	ConnMap_t::iterator iter = imconn_map->find(handle);
	if(iter != imconn_map->end()){
		pConn = iter->second;
	}
	return pConn;
}

void imconn_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam){
	vrprintf("imconn\n");
	ConnMap_t* conn_map = (ConnMap_t *)callback_data;
	CImConn* pConn = FindImConn(conn_map,handle);
	switch(msg){
		case NETLIB_MSG_READ:
			pConn->OnRead();
			break;
	}
}

void CImConn::OnRead(){
	vrprintf("onRead\n");
	while(1){
		uint32_t free_buf_len = m_in_buf.GetAllocSize() - m_in_buf.GetWriteOffset();
		if(free_buf_len < READ_BUF_SIZE)
			m_in_buf.Extend(READ_BUF_SIZE);
		int ret = netlib_recv(handle,m_in_buf.GetBuffer()+m_in_buf.GetWriteOffset(),READ_BUF_SIZE);
		if(ret <= 0){
			break;
		}
		m_in_buf.IncWriteOffset(ret);



	}
}
