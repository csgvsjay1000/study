#include <stdio.h>

int main(){
	union{
		short value;
		char union_bytes[sizeof(short)];
	}test;

	printf("%lu\n",sizeof(test));
	printf("short %lu\n",sizeof(short));
	
	test.value = 0x0102;
	printf("value %d\n",test.value);
	if((test.union_bytes[0] == 1) && (test.union_bytes[1] == 2)){
		printf("big endian\n");
	}else if((test.union_bytes[1] == 1) && (test.union_bytes[0] == 2)){
		printf("little endian\n");
	}

	return 0;
}
