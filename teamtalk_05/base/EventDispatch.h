#ifndef __EVENTDISPATCH__
#define __EVENTDISPATCH__

#include "ostype.h"
#include "util.h"
#include "Lock.h"

enum{
	SOCKET_READ 	= 0x1,
	SOCKET_WRITE 	= 0x2,
	SOCKET_EXCEP 	= 0x4,
	SOCKET_ALL  	= 0x7
};

class CEventDispatch{
public:
	void AddEvent(SOCKET fd,uint8_t socket_event);
	void RemoveEvent(SOCKET fd,uint8_t socket_event);

	void AddTimer(callback_t callback,void* user_data,uint64_t interval);
	void StartDispatch(uint32_t wait_timeout = 100);

	static CEventDispatch* Instance();

protected:
	CEventDispatch();

private:
	void _CheckTimer();
	typedef struct {
		callback_t 		callback;
		void* 			user_data;
		uint64_t 		interval;
		uint64_t 		next_tick;
	}TimerItem;
	
	int 	m_epfd;

	list<TimerItem*> m_timer_list;

	static CEventDispatch* m_pEventDispatch;
};

#endif
