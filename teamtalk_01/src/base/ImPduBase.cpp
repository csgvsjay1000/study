#include "ImPduBase.h"
#include "IM.BaseDefine.pb.h"

using namespace IM::BaseDefine;

CImPdu::CImPdu(){
	m_pdu_header.version = IM_PDU_VERSION;
	m_pdu_header.flag = 0;
	m_pdu_header.service_id = SID_OTHER;
	m_pdu_header.command_id = 0;
	m_pdu_header.seq_num = 0;
	m_pdu_header.reversed = 0;
}

bool CImPdu::IsPduAvailable(uint8_t* buf,uint32_t len,uint32_t& pdu_len){
	
	return true;
}
CImPdu* CImPdu::ReadPdu(uint8_t* buf,uint32_t len){
	


	return NULL;
}

void WriteHeader(){
	uint8_t* buf = GetBuffer();
	CByteStream::WriteInt32(buf,m_buf.GetWriteOffset());
	CByteStream::WriteUint16(buf+4,m_pdu_header.version);
	CByteStream::WriteUint16(buf+6,m_pdu_header.flag);
	CByteStream::WriteUint16(buf+8,m_pdu_header.service_id);
	CByteStream::WriteUint16(buf+10,m_pdu_header.command_id);
	CByteStream::WriteUint16(buf+12,m_pdu_header.seq_num);
	CByteStream::WriteUint16(buf+14,m_pdu_header.reversed);

}

void CImPdu::SetPBMsg(const google::protobuf::MessageLite* msg){
	m_buf.Read(NULL,m_buf.GetWriteOffset());
	m_buf.Write(NULL,sizeof(PduHeader_t));
	uint32_t msg_size = msg->ByteSize();
	uint8_t szData[msg_size];
	if(!msg->SerializeToArray(szData,msg_size)){
		vrprintf("pb msg miss required fields.\n");
	}
	m_buf.Write(szData,msg_size);
	WriteHeader();
}
