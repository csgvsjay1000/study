#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	//int fd = creat("test",1644);	
	int fd = open("test",O_RDWR|O_CREAT|O_TRUNC,0644);	
	char *buf = "test";
	write(fd,buf,strlen(buf));
	char readbuf[1024];
	lseek(fd,0,SEEK_SET);
	read(fd,readbuf,1024);
	printf("readbuf: %s\n",readbuf);
	return 0;
}
