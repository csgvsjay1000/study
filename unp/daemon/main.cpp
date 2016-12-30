#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int fdlimit = sysconf(_SC_OPEN_MAX);
	printf("fdlimit %d\n",fdlimit);
	return 0;
}
