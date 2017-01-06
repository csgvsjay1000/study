#include "EventDispatch.h"
#include "BaseSocket.h"

CEventDispatch* CEventDispatch::m_pEventDispatch = NULL;

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

void CEventDispatch::StartDispatch(uint32_t wait_timeout){
	struct epoll_event events[1024];
	int nfds = 0;
	if(running){
		return;
	}
	running = true;
	while(running){
		nfds = epoll_wait(m_epfd,events,1024,wait_timeout);
		for(int i=0;i<nfds;i++){
			int ev_fd = events[i].data.fd;
			CBaseSocket *pSocket = FindBaseSocket(ev_fd);
			if(!pSocket){
				vrprintf("pSocket == NULL\n");
				continue;
			}
			
			if(events[i].events & EPOLLIN){
				pSocket->OnRead();
			}
		}
	}
}
