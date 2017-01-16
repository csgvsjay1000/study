#ifndef __IMPDUBASE_H__
#define __IMPDUBASE_H__

#include "UtilPdu.h"
#include <google/protobuf/message_lite.h>

#define IM_PDU_HEADER_LEN 	16
#define IM_PDU_VERSION 		1

typedef struct {
	uint32_t 		length; 		// the whole pdu length
	uint16_t 		version; 		// pdu version number
	uint16_t 		flag; 			// not used
	uint16_t 		service_id; 	
	uint16_t 		command_id; 	
	uint16_t 		seq_num; 		// 包序号
	uint16_t 		reversed; 		// 保留
}PduHeader_t;

class CImPdu{
public:
	CImPdu();
	~CImPdu(){}

	uint8_t* GetBuffer(){return m_buf.GetBuffer();}
	
	static bool IsPduAvailable(uint8_t* buf,uint32_t len,uint32_t& pdu_len);
	static CImPdu* ReadPdu(uint8_t* buf,uint32_t len);

	void WriteHeader();

	void SetPBMsg(const google::protobuf::MessageLite* msg);

protected:
	CSimpleBuffer 	m_buf;
	PduHeader_t 	m_pdu_header;

};

#endif
