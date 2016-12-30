#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "Student.pb.h"


int main(){

	std::cout<<"server start..."<<std::endl;
	
	int sockfd = socket(AF_INET,SOCK_STREAM,0);

	std::cout<<"sockfd "<<sockfd <<std::endl;
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12138);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	int bind_ret = bind(sockfd,(struct sockaddr *)&addr,sizeof(addr));
	
	std::cout<<"bind_ret "<<bind_ret<<std::endl;
	
	int listen_ret =  listen(sockfd,1024);
	
	std::cout<<"listen_ret "<<listen_ret<<std::endl;

	struct sockaddr_in addr_client;
	socklen_t sin_size = 0;
	sin_size = sizeof(addr_client);
	char recvMsg[1024];
	Student stu;
	
	for(;;){
		int accept_sockfd = accept(sockfd,(struct sockaddr *)&addr_client,&sin_size);
		//std::cout<<"accept_sockfd "<<accept_sockfd<<"  "<<strerror(errno) << std::endl;
		printf("accept_sockfd %d  %s\n",accept_sockfd,strerror(errno));
		ssize_t recv_ret = recv(accept_sockfd,recvMsg,sizeof(recvMsg),0);
		stu.ParseFromString(recvMsg);

		printf("recv_ret %zd %s",recv_ret,stu.name().c_str());

	}
	
	close(sockfd);
	return 0;
}
