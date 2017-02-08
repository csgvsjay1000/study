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
			CBaseSocket* pSocket = FindBaseSocket(ev_fd);
			if(!pSocket)
				continue;
			if(events[i].events&EPOLLIN){
				pSocket->OnRead();
				vrprintf("OnRead\n");
			}
			if(events[i].events&EPOLLOUT){
			
				vrprintf("OnWrite\n");
			}
			//外带数据、socket出错、对方正常关闭socket，有些系统可以检测
			if(events[i].events&(EPOLLPRI|EPOLLERR|EPOLLHUP)){
				pSocket->OnClose();
				vrprintf("OnClose\n");
			}
			_CheckTimer();
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
	ev.events = EPOLLIN  | EPOLLET | EPOLLPRI | EPOLLERR | EPOLLHUP;
	ev.data.fd = fd;
	epoll_ctl(m_epfd,EPOLL_CTL_ADD,fd,&ev);
}
void CEventDispatch::RemoveEvent(SOCKET fd,uint8_t socket_event){
	epoll_ctl(m_epfd,EPOLL_CTL_DEL,fd,NULL);
}

void CEventDispatch::AddTimer(callback_t callback,void* user_data,uint64_t interval){
	list<TimerItem*>::iterator it;
	for(it=m_timer_list.begin();it!=m_timer_list.end();it++){
		TimerItem* pItem = *it;
		if(pItem->callback == callback && pItem->user_data == user_data){
			pItem->interval = interval;
			pItem->next_tick = get_tick_count()+interval;
			return;
		}
	}
	TimerItem* pItem = new TimerItem;
	pItem->callback = callback;
	pItem->user_data = user_data;
	pItem->interval = interval;
	pItem->next_tick = get_tick_count();
	m_timer_list.push_back(pItem);
}
void CEventDispatch::_CheckTimer(){
	uint64_t curr_tick = get_tick_count();
	list<TimerItem*>::iterator it;
	for(it=m_timer_list.begin();it!=m_timer_list.end();){
		TimerItem* pItem = *it;
		it++;
		if(curr_tick>=pItem->next_tick){
			pItem->next_tick += pItem->interval;
			pItem->callback(pItem->user_data,NETLIB_MSG_TIMER,0,NULL);
		}
	}
}
