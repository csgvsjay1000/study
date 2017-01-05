#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <arpa/inet.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static bool stop = false;

static void handle_term(int sig){
	stop = true;
}

int main(int argc,char* argv[]){
	signal(SIGTERM,handle_term);
	if(argc < 3){
		printf("usage: %s ip_address port_number backlog\n",argv[0]);
		return 1;
	}
	const char *ip = argv[1];
	int port = atoi(argv[2]);
	int backlog = atoi(argv[3]);

	int sock = socket(AF_INET,SOCK_STREAM,0);
	assert(sock>0);
	
	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	inet_pton(AF_INET,ip,&address.sin_addr);
	fcntl(sock,F_SETFL,O_NONBLOCK|fcntl(sock,F_GETFL));
	
	int ret = bind(sock,(struct sockaddr*)&address,sizeof(address));
	assert(ret != -1);
	
	ret = listen(sock,backlog);
	assert(ret != -1);
	char buf[1024];
	while(!stop){
		struct sockaddr_in client_address;
		int len = sizeof(sockaddr_in);
		int client = accept(sock,(struct sockaddr *)&client_address,(socklen_t *)&len);
		printf("client %d\n",client);
		if(client>0){
			ret = recv(client,buf,sizeof(buf),0);
			printf("buf: %s\n",buf);
		}
		close(client);
		//sleep(1);
	}
	close(sock);
	return 0;
}
