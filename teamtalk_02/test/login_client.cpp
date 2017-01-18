#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include "IM.Login.pb.h"

using namespace IM::Login;

typedef struct {
	uint16_t length;
	uint16_t service_id;
	uint16_t command_id;
}PduHeader_t;

void WriteUint16(uint8_t* buf,uint16_t data){
	buf[0] = static_cast<uint8_t>(data >> 8);
	buf[1] = static_cast<uint8_t>(data & 0xFF);
}

int main(){
	printf("client starting...\n");
	int m_socket = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(12138);
	const char *ip = "192.168.200.85";
	serv_addr.sin_addr.s_addr = inet_addr(ip);
	printf("m_socket: %d\n",m_socket);
	int ret = connect(m_socket,(sockaddr*)&serv_addr,sizeof(serv_addr));
	if(ret < 0){
		close(m_socket);
		return -1;
	}
	PduHeader_t pdu;
	uint8_t buf[1024];
	IMLoginReq msg;
	msg.set_user_name("test_yyy");
	msg.set_password("test_pass");
	msg.set_online_status(IM::BaseDefine::USER_STATUS_ONLINE);
	msg.set_client_type(IM::BaseDefine::CLIENT_TYPE_IOS);
	uint32_t msg_size = msg.ByteSize();

	uint8_t msg_data[msg_size];
	int serial_ret = msg.SerializeToArray(msg_data,msg_size);
	printf("serial_ret %d\n",serial_ret);
	pdu.length = sizeof(pdu)+msg_size;
	pdu.service_id = 199;
	pdu.command_id = 239;
 	WriteUint16(buf,pdu.length);
 	WriteUint16(buf+2,pdu.service_id);
 	WriteUint16(buf+4,pdu.command_id);
	memcpy(buf+sizeof(pdu),msg_data,msg_size);
	int send_ret = send(m_socket,buf,pdu.length,0);
	printf("send_ret %d\n",send_ret);
	return 0;
}
