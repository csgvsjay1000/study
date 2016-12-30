#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "msg.pb.h"
#include <unistd.h>
#include <string>
#include <iostream>
#define SERVER_PORT 12138
#define BACKLOG 20
#define MAX_CON_NO 10
#define MAX_DATA_SIZE 4096

int main(int argc,char *argv[]){
	printf("hello\n");
	struct sockaddr_in serverSockaddr,clientSockaddr;
	char sendBuf[MAX_DATA_SIZE],recvBuf[MAX_DATA_SIZE];
	int sendSize,recvSize;
	int sockfd,clientfd;
	int on=1;
	socklen_t sinSize=0;
	char username[32];
	int pid;
	
	if(argc != 2){
		printf("usage: ./server [username]\n");
		exit(1);
	}
	
	strcpy(username,argv[1]);
	printf("username:%s\n",username);
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("fail to establish a socket");
		exit(1);
	}

	printf("Success to establish a socket...\n");

	serverSockaddr.sin_family=AF_INET;
	serverSockaddr.sin_port=htons(SERVER_PORT);
	serverSockaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	bzero(&(serverSockaddr.sin_zero),8);

	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

	if(bind(sockfd,(struct sockaddr *)&serverSockaddr,sizeof(struct sockaddr))==-1){
		perror("fail to bind");
		exit(1);
	}
	printf("Success to bind the socket...\n");
	if(listen(sockfd,BACKLOG)==-1){
		 perror("fail to listen");
		 exit(1);
	}

	sinSize=sizeof(clientSockaddr);//注意要写上，否则获取不了IP和端口
	while(1){
		if((clientfd=accept(sockfd,(struct sockaddr  *)&clientSockaddr, &sinSize))==-1){
			perror("fail to accept");
			exit(1);

		}
		printf("Success to accpet a connection request...\n");
		 printf(" %s:%d join in!\n",inet_ntoa(clientSockaddr.sin_addr),ntohs(clientSockaddr.sin_port));
		
		 if((pid=fork())<0){
			perror("fork error\n");
		 }else if(pid==0){
			//child
			 lm::helloworld msg;
			 char msgBuf[1024]={0};
			 while(1){
				 if((recvSize=recv(clientfd,msgBuf,MAX_DATA_SIZE,0))==-1){
					 perror("fail to receive datas");
					 exit(1);
				 }
				 msg.ParseFromArray(msgBuf,1024);
				// printf("Client:%s\n",msg.str());
				std::cout<<"Client:"<<msg.str()<<std::endl;
				 memset(msgBuf,0,MAX_DATA_SIZE);
			 }
		 }
	}
	close(sockfd);

	
	return 0;
}

