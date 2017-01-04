#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


#define MAX_FD 65536
#define MAX_EVENT_NUMBER 10000

extern int addfd(int epollfd,int fd,bool one_shot);
extern int removefd(int epollfd,int fd);

void show_error(int connfd,const char *info){
	printf("%s",info);
	send(connfd,info,strlen(info),0);
	close(connfd);
}

int main(int argc,char* argv[]){
	if(argc <=2 ){
		printf("usage: %s ip_address port_number\n",argv[0]);
		return 1;
	}
	
	

	return 0;
}
