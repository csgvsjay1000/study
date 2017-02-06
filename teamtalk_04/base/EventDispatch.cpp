#include "EventDispatch.h"
#include <time.h>
#include <sys/time.h>

using namespace std;

CEventDispatch* CEventDispatch::m_pEventDispatch = NULL;

uint64_t get_tick_count(){
	struct timeval tval;
	uint64_t ret_tick;
	gettimeofday(&tval,NULL);
	ret_tick = tval.tv_sec*1000L + tval.tv_usec/1000L;
	return ret_tick;
}

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
		//printf("epoll_wait()\n");
		for(int i=0;i<nfds;i++){
			int ev_fd = events[i].data.fd;
			if(events[i].events & EPOLLIN){
				printf("readfd");
			}
		}
		_CheckTimer();
	}
}
void CEventDispatch::StopDispatch(){

}
CEventDispatch* CEventDispatch::Instance(){
	if(m_pEventDispatch == NULL)
		m_pEventDispatch = new CEventDispatch();
	return m_pEventDispatch;
}

void CEventDispatch::AddTimer(callback_t callback,void* user_data,uint64_t interval){
	list<TimerItem*>::iterator it;
	for(it = m_timer_list.begin();it!=m_timer_list.end();it++){
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
	pItem->next_tick = get_tick_count()+interval;
	m_timer_list.push_back(pItem);
}

void CEventDispatch::_CheckTimer(){
	uint64_t curr_tick = get_tick_count();
	list<TimerItem*>::iterator it;

	for(it=m_timer_list.begin();it!=m_timer_list.end();){
		TimerItem* pItem = *it;
		it++;
		if(curr_tick >= pItem->next_tick){
			pItem->next_tick += pItem->interval;
			pItem->callback(pItem->user_data,1,0,NULL);
		}
	}
}
