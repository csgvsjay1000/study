#include "EventDispatch.h"

CEventDispatch* CEventDispatch::m_pEventDispatch = NULL;

CEventDispatch::CEventDispatch(){
	m_epfd = epoll_create(1024);
}

void CEventDispatch::AddEvent(int fd,uint8_t socket_event){
	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLOUT | EPOLLET;
	ev.data.fd = fd;
	epoll_ctl(m_epfd,EPOLL_CTL_ADD,fd,&ev);
}
void CEventDispatch::StartDispatch(uint32_t wait_timeout){
	struct epoll_event events[1024];
	int nfds = 0;
	
	while(true){
		nfds = epoll_wait(m_epfd,events,1024,100);
		for(int i=0;i<nfds;i++){
			int ev_fd = events[i].data.fd;
			if(events[i].events & EPOLLIN){
				printf("readfd");
			}
		}
	}
}
void CEventDispatch::StopDispatch(){

}
CEventDispatch* CEventDispatch::Instance(){
	if(m_pEventDispatch == NULL)
		m_pEventDispatch = new CEventDispatch();
	return m_pEventDispatch;
}
