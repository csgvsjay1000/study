#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "init_socket.h"

int main(){

	int listen_fd;
	int connect_fd;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	bzero(&server_addr,sizeof(struct sockaddr_in));
	bzero(&client_addr,sizeof(struct sockaddr_in));
	
	init_socket(&listen_fd,&server_addr);

	socklen_t addrlen = sizeof(struct sockaddr_in);
	pid_t pid;

	while(1){
		connect_fd = accept(listen_fd,(struct sockaddr *)&client_addr,&addrlen);
		if(connect_fd == -1)
			continue;
		if((pid=fork())>0){
			close(connect_fd);
			continue;
		}else if(pid == 0){
			close(listen_fd);
			printf("pid %d process http session from %s : %d\n",getpid(),inet_ntoa(client_addr.sin_addr),htons(client_addr.sin_port));
			
		}

		printf("accept\n");
	}

	return 0;
}
