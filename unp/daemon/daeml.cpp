#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc,char* argv[]){
	printf("daemon...\n");

	if(fork()>0){
		exit(0);
	}
	setsid();
	umask(0);
	for(int i=0;i<3;i++){
		close(i);
	}
	
	execv(argv[1],argv+1);

	chdir("/");
	return 0;
}
