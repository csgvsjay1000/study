#ifndef __UTIL__
#define __UTIL__

#include "ostype.h"
#include "UtilPdu.h"
#include <string.h>

class CRefObject{

public:
	void AddRef();
	void ReleaseRef();
private:
	int m_refCount;
};

#endif
