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

CImPdu* CImPdu::ReadPdu(uint8_t* buf,uint32_t len){
	uint32_t pdu_len = 0;
	if(!IsPduAvailable(buf,len,pdu_len)){
		return NULL;
	}
	uint16_t service_id = CByteStream::ReadUint16(buf+8);
	uint16_t command_id = CByteStream::ReadUint16(buf+10);
	
	vrprintf("service_id %d, command_id %d, \n",service_id,command_id);


	return NULL;
}
bool CImPdu::IsPduAvailable(uint8_t* buf,uint32_t len,uint32_t& pdu_len){
	pdu_len = CByteStream::ReadUint32(buf);
	vrprintf("pdu_len %d\n",pdu_len);

	return true;
}


void CImPdu::WriteHeader(){
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
