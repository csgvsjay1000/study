#include "EventDispatch.h"

CEventDispatch::CEventDispatch(){
	m_epfd = epoll_create(1024);
}

CEventDispatch::~CEventDispatch(){
	close(m_epfd);
}

CEventDispatch* CEventDispatch::Instance(){
	if(m_pEventDispatch == NULL){
		m_pEventDispatch = new CEventDispatch();
	}
	return m_pEventDispatch;
}

void CEventDispatch::AddEvent(int fd,uint8_t socket_event){
	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLOUT | EPOLLET | EPOLLPRI | EPOLLERR | EPOLLHUP;
	ev.data.fd = fd;
	if(epoll_ctl(m_epfd,EPOLL_CTL_ADD,fd,&ev)!=0){

	}
}

void CEventDispatch::AddTimer(callback_t callback, void* user_data, uint64_t interval){

}

void CEventDispatch::RemoveTimer(callback_t callback, void* user_data){

}
