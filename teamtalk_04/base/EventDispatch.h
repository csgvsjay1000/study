#ifndef __EVENTDISPATCH__
#define __EVENTDISPATCH__

#include "ostype.h"
#include <list>

using namespace std;

class CEventDispatch{
public:

	CEventDispatch();
	~CEventDispatch();

	void AddEvent(int fd,uint8_t socket_event);
	void StartDispatch(uint32_t wait_timeout=100);
	void StopDispatch();

	void AddTimer(callback_t callback,void* user_data,uint64_t interval);

	static CEventDispatch* Instance();

private:
	void _CheckTimer();
	typedef struct{
		callback_t callback;
		void* user_data;
		uint64_t interval;
		uint64_t next_tick;
	}TimerItem;

private:
	static CEventDispatch* m_pEventDispatch;
	int 	m_epfd;
	list<TimerItem*> m_timer_list;
};

#endif
