#ifndef __UTIL__
#define __UTIL__

#include "ostype.h"
#include "UtilPdu.h"
#include <string.h>

uint64_t get_tick_count();

class CRefObject{

public:
	void AddRef();
	void ReleaseRef();
private:
	int m_refCount;
};

#endif
