#include "UtilPdu.h"

CSimpleBuffer::CSimpleBuffer(){
	m_buffer = NULL;
	m_alloc_size = 0;
	m_write_offset = 0;
}

CSimpleBuffer::~CSimpleBuffer(){
	if(m_buffer){
		free(m_buffer);
		m_buffer = NULL;
	}
}


void CSimpleBuffer::Extend(uint32_t len){
	m_alloc_size = m_write_offset + len;
	m_alloc_size += m_alloc_size >> 2;
	uint8_t* buf_new = (uint8_t*)realloc(m_buffer,m_alloc_size); 
	m_buffer = buf_new;
}
uint32_t CSimpleBuffer::Write(void* buf,uint32_t len){
	if(m_write_offset+len > m_alloc_size){
		Extend(len);
	}
	if(buf){
		memcpy(m_buffer+m_write_offset,buf,len);
	}
	m_write_offset += len;
	return len;
}
uint32_t CSimpleBuffer::Read(void* buf,uint32_t len){
	if(len > m_write_offset)
		len = m_write_offset;
	if(buf)
		memcpy(buf,m_buffer,len);
	m_write_offset -= len;
	memmove(m_buffer,m_buffer+len,m_write_offset);
	return len;
}
