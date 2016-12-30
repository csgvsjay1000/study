#include <ev.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

#define PORT 9999
#define BUFFER_SIZE 1024

void read_cb(struct ev_loop *loop, struct ev_io *watcher, int revents);
void accept_cb(struct ev_loop *loop, struct ev_io *watcher, int revents){
	struct sockaddr_in client_addr;  
	socklen_t client_len = sizeof(client_addr); 
	int client_sd;  
	struct ev_io *w_client = (struct ev_io*)malloc(sizeof(struct ev_io));
	if(EV_ERROR & revents){
		printf("error event in accept");  
		return;
	}
	client_sd = accept(watcher->fd,(struct sockaddr*)&client_addr,&client_len);
	if(client_sd < 0){
		printf("accept error");  
		return;
	}
	printf("someone connected.\n");
	ev_io_init(w_client,read_cb,client_sd,EV_READ);
	ev_io_start(loop,w_client);
}

void read_cb(struct ev_loop *loop, struct ev_io *watcher, int revents){
	char buffer[BUFFER_SIZE];
	ssize_t read;
	if(EV_ERROR & revents)  
	{  
	  printf("error event in read");  
	  return;  
	} 
	read = recv(watcher->fd,buffer,BUFFER_SIZE,0);
	if(read < 0){
		printf("read error");
		return;
	}
	if(read == 0){
		printf("someone disconnected.\n");
		ev_io_stop(loop,watcher);
		free(watcher);
		return;
	}
	 printf("get the message:%s\n",buffer);  
	 send(watcher->fd, buffer, read, 0); 
	 bzero(buffer, read); 
}

int main(int argc, char* argv[]){
	printf("hello\n");
	
	struct ev_loop *loop = ev_default_loop(0);
	int sd;
	struct sockaddr_in addr;
	int addr_len = sizeof(addr);
	struct ev_io socket_accept;
	sd = socket(PF_INET, SOCK_STREAM, 0);
	bzero(&addr, sizeof(addr));  
	addr.sin_family = AF_INET;  
	addr.sin_port = htons(PORT);  
	addr.sin_addr.s_addr = INADDR_ANY;  
	bind(sd, (struct sockaddr*) &addr, sizeof(addr));
	listen(sd,2);

	ev_io_init(&socket_accept,accept_cb,sd,EV_READ);
	ev_io_start(loop,&socket_accept);

	while(1){
		ev_loop(loop,0);
	}

	return 0;
}
