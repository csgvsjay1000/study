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
	void StartDispatch(uint32_t wait_timeout = 100);

	static CEventDispatch* Instance();

protected:
	CEventDispatch();

private:
	int 	m_epfd;

	static CEventDispatch* m_pEventDispatch;
};

#endif
