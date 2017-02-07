#include "http_session.h"

int http_session(int *connect_fd,struct sockaddr_in *client_addr){
	char recv_buf[RECV_BUFFER_SIZE+1];
	unsigned char send_buf[SEND_BUFFER_SIZE+1];
	unsigned char file_buf[FILE_MAX_SIZE+1];

	memset(send_buf,'\0',sizeof(send_buf));
	memset(file_buf,'\0',sizeof(file_buf));
	int read_bytes;
	while(1){
		memset(recv_buf,'\0',sizeof(recv_buf));
		read_bytes = recv(*connect_fd,recv_buf,RECV_BUFFER_SIZE,0);
		if(read_bytes>0){

		}
	}

	return 0;
}
