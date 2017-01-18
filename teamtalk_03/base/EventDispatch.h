#ifndef __EVENTDISPATCH__
#define __EVENTDISPATCH__

#include "ostype.h"

class CEventDispatch{
public:
	void AddEvent(int fd,uint8_t socket_event);
	void StartDispatch(uint32_t wait_timeout=100);
	void StopDispatch();

	static CEventDispatch* Instance();

private:
	static CEventDispatch* m_pEventDispatch;
};

#endif
