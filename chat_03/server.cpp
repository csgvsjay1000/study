#include <stdio.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SERVER_PORT 12138
#define CON_QUEUE 20
#define MAX_DATA_SIZE 4096
#define MAX_EVENTS 500


void AcceptConn(int sockfd,int epollfd);
void Handle(int clientfd);

int main(int argc,char *agrv[]){
	printf("hello\n");
	struct sockaddr_in serverSockaddr;
	int sockfd;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	serverSockaddr.sin_family = AF_INET;
	serverSockaddr.sin_port = htons(SERVER_PORT);
	bzero(&(serverSockaddr.sin_zero),8);
	
	int on = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
	bind(sockfd,(struct sockaddr *)&serverSockaddr,sizeof(struct sockaddr));
	listen(sockfd,CON_QUEUE);

	int epollfd;
	struct epoll_event eventList[MAX_EVENTS];
	epollfd = epoll_create(MAX_EVENTS);
	struct epoll_event event;
	event.events = EPOLLIN|EPOLLET;
	event.data.fd = sockfd;
	epoll_ctl(epollfd,EPOLL_CTL_ADD,sockfd,&event);

	while(1){
		int timeout = 300;
		int ret = epoll_wait(epollfd,eventList,MAX_EVENTS,timeout);
		if(ret == 0){
			continue;
		}
		for(int i=0;i<ret;i++){
			if(eventList[i].data.fd == sockfd){
				AcceptConn(sockfd,epollfd);
			}else{
				Handle(eventList[i].data.fd);
			}
		}

	}
	close(epollfd);
	close(sockfd);
	return 0;
}

void AcceptConn(int sockfd,int epollfd){
	printf("accept new client\n");
	struct sockaddr_in sin;
	socklen_t len = sizeof(struct sockaddr_in);
	bzero(&sin,len);

	int confd = accept(sockfd,(struct sockaddr *)&sin,&len);

	struct epoll_event event;
	event.data.fd = confd;
	event.events = EPOLLIN|EPOLLET;
	epoll_ctl(epollfd,EPOLL_CTL_ADD,confd,&event);
	return;
}

void Handle(int clientfd){
	int recvLen = 0;
	char recvBuf[MAX_DATA_SIZE];
	memset(recvBuf,0,sizeof(recvBuf));
	recvLen = recv(clientfd,(char *)recvBuf,MAX_DATA_SIZE,0);
	printf("接收的数据:%s\n",recvBuf);
}
