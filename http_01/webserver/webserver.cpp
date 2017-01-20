#include "webserver.h"

int WebServer::ServerInit(uint16_t port){
	struct sockaddr_in sin;
	int on = 1;
	httpd = socket(PF_INET,SOCK_STREAM,0);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	bzero(&(sin.sin_zero),8);
	setsockopt(httpd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
	bind(httpd,(struct sockaddr *)&sin,sizeof(struct sockaddr));
	listen(httpd,100);
	return port;	
}

int WebServer::ServerAccept(){
	sockaddr_in cli_sin;
	socklen_t cli_len = sizeof(cli_sin);
	int cli_fd;
	cli_fd = accept(httpd,(sockaddr*)&cli_sin,&cli_len);
	printf("连接进来的IP:%s:%d\n",inet_ntoa(cli_sin.sin_addr),ntohs(cli_sin.sin_port));

}

int WebServer::ServerRequest(int cli_fd){
	char buf[1024];
	int size = 1024;
	memset(buf,0,sizeof(buf));
	int i=1;
	while(i>0 && strcmp("\n",buf)){

	}
}

int WebServer::get_line(int cli_fd,char *buf,int size){
	int i=0;
	char c = '\0';
	int n;

}

int WebServer::Page_200(int cli_fd){
	char buf[1024];
	sprintf(buf,"HTTP/1.1 200 OK\r\n");
	send(cli_fd,buf,strlen(buf),0);
}
int WebServer::Page_501(int cli_fd){
	char buf[1024];
	sprintf(buf,"HTTP/1.1 200 OK\r\n");
	send(cli_fd,buf,strlen(buf),0);
}
