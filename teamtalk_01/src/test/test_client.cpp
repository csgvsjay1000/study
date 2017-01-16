#include <iostream>
#include "netlib.h"
#include "Thread.h"
#include "Client.h"

#define MAX_LINE_LEN 1024

using namespace std;

int main(int argc,char* argv[]){
	printf("test_client\n");
	CClient client;
	string strIp = "192.168.200.85";
	client.connect(strIp,12345);
	return 0;
}

