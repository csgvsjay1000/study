#include "init_socket.h"
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int init_socket(int *listen_fd,struct sockaddr_in *server_addr){
	*listen_fd = socket(AF_INET,SOCK_STREAM,0);
	
	int opt = SO_REUSEADDR;
	setsockopt(*listen_fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

	server_addr->sin_family = AF_INET;
	server_addr->sin_port = htons(PORT);
	server_addr->sin_addr.s_addr = htonl(INADDR_ANY);

	bind(*listen_fd,(struct sockaddr*)server_addr,sizeof(struct sockaddr_in));

	listen(*listen_fd,BACKLOG);
	return 0;
}


