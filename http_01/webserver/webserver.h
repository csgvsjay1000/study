#ifndef __WEBSERVER__
#define __WEBSERVER__

#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <thread>//使用c++11的多线程
#include <string.h>

using namespace std;

class WebServer{
public:
	int ServerInit(uint16_t port);
	int ServerError(string str);
	int ServerAccept();
	int ServerClose();
	int ServerRequest(int cli_fd);
	int get_line(int cli_fd,char *buf,int size);

	int Page_200(int cli_fd);
	int Page_501(int cli_fd);

private:
	int httpd;
};

#endif
