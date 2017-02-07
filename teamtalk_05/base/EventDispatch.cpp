#include "EventDispatch.h"
#include "BaseSocket.h"

#define MIN_TIMER_DURAION 100

CEventDispatch* CEventDispatch::m_pEventDispatch = NULL;

CEventDispatch::CEventDispatch(){
	m_epfd = epoll_create(1024);
}

void CEventDispatch::StartDispatch(uint32_t wait_timeout){
	struct epoll_event events[1024];
	int nfds = 0;
	bool running = true;
	while(running){
		nfds = epoll_wait(m_epfd,events,1024,wait_timeout);
		for(int i=0;i<nfds;i++){
			int ev_fd = events[i].data.fd;
		}
	}
}

CEventDispatch* CEventDispatch::Instance(){
	if(m_pEventDispatch == NULL){
		m_pEventDispatch = new CEventDispatch();
	}
	return m_pEventDispatch;
}

void CEventDispatch::AddEvent(SOCKET fd,uint8_t socket_event){
	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLOUT | EPOLLET | EPOLLPRI | EPOLLERR | EPOLLHUP;
	ev.data.fd = fd;
	epoll_ctl(m_epfd,EPOLL_CTL_ADD,fd,&ev);
}
