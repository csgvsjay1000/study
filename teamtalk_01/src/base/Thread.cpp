#include "Thread.h"

void CThread::StartThread(){
	pthread_create(&m_thread_id,NULL,StartRoutine,this);
}	
void* CThread::StartRoutine(void *arg){
	CThread* pThread = (CThread*)arg;
	pThread->OnThreadRun();
	return NULL;
}

