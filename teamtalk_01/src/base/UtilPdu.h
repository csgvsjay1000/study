#ifndef __UTILPDU__
#define __UTILPDU__

#include "netlib.h"

class CSimpleBuffer{
public:
	CSimpleBuffer();
	~CSimpleBuffer();
	uint8_t* GetBuffer(){return m_buffer;}
	uint32_t GetAllocSize(){return m_alloc_size; }
	uint32_t GetWriteOffset() {return m_write_offset;}

	void Extend(uint32_t len);
	uint32_t Write(void* buf,uint32_t len);
	uint32_t Read(void* buf,uint32_t len);

	void IncWriteOffset(uint32_t len){m_write_offset+=len;}

private:
	uint8_t* 		m_buffer;
	uint32_t 		m_alloc_size;
	uint32_t 		m_write_offset;

};

#endif
