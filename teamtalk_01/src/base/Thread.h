#ifndef __TT_THREAD_H__
#define __TT_THREAD_H__

#include <pthread.h>

class CThread{
public:
	CThread();
	~CThread();
	static void* StartRoutine(void *arg);
	virtual void StartThread();
	virtual void OnThreadRun() = 0;

protected:
	pthread_t m_thread_id;

};

#endif
