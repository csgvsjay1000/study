#include <netinet/in.h>

#define RECV_BUFFER_SIZE 1024
#define SEND_BUFFER_SIZE 1024*1024
#define URI_SIZE 128

#define TIME_OUT_SEC 	10
#define TIME_OUT_USEC 	0

#define FILE_OK 		200
#define FILE_FORBIDEN 	403
#define FILE_NOT_FOUND 	404
#define UNALLOW_METHOD 	405
#define FILE_TOO_LARGE 	413
#define FILE_MAX_SIZE 	1024*1024

int http_session(int *connect_fd,struct sockaddr_in *client_addr);

