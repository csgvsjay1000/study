#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
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

uint16_t ReadUint16(uint8_t* buf){
	uint16_t data =(buf[0]<<8)|buf[1];
	return data;
}

int main(){
	printf("server starting...\n");
	int m_socket = socket(AF_INET, SOCK_STREAM, 0);
	int reuse = 1;
	int ret = setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(reuse));
	sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(12138);
	const char *ip = "192.168.200.85";
	serv_addr.sin_addr.s_addr = inet_addr(ip);
	printf("m_socket: %d\n",m_socket);
	ret = bind(m_socket, (sockaddr*)&serv_addr, sizeof(serv_addr));
	ret = listen(m_socket, 64);

	printf("ret: %d\n",ret);

	uint8_t buf[1024];
	
	

	while(1){
		sockaddr_in client_addr;
		socklen_t addr_len = sizeof(sockaddr_in);
		int connfd = accept(m_socket,(sockaddr*)&client_addr,&addr_len);
		if(connfd < 0){
			break;
		}
		recv(connfd,buf,1024,0);

		PduHeader_t pdu;
		uint16_t length = ReadUint16(buf);
		uint16_t service_id = ReadUint16(buf+2);
		uint16_t command_id = ReadUint16(buf+4);
		
		IMLoginReq msg;
		if(msg.ParseFromArray(buf+sizeof(pdu),length - sizeof(pdu))){
			const char *user_name = msg.user_name().c_str();
			printf("user_name: %s\n",user_name);
		}
		
		

		printf("service_id: %d, command_id: %d \n",service_id,command_id);
		close(connfd);
	}

	close(m_socket);
	return 0;
}
