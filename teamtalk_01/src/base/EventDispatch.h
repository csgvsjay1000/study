#ifndef __EVENT_DISPATCH_H__
#define __EVENT_DISPATCH_H__

#include "netlib.h"

class CEventDispatch{
public:
	CEventDispatch();
	~CEventDispatch();
	void AddEvent(int fd,uint8_t socket_event);
	void AddTimer(callback_t callback, void* user_data, uint64_t interval);
	void RemoveTimer(callback_t callback, void* user_data);

	static CEventDispatch* Instance();
private:
	static CEventDispatch* m_pEventDispatch;
	int m_epfd;

};

#endif
