#include <stdio.h>
#include <string>
#include <string.h>
#include "Client.h"

using namespace std;

#define MAX_LINE_LEN 	1024
string g_cmd_string[10];
int g_cmd_num;
CClient* g_pClient = NULL;
void split_cmd(char* buf){
	int len = strlen(buf);
	string element;
	g_cmd_num = 0;
	for(int i=0;i<len;i++){
		//printf("%c",buf[i]);
		if(buf[i]==' '|| buf[i]=='\t'){
			if(!element.empty()){
				g_cmd_string[g_cmd_num++] = element;
				printf("element: %s\n",element.c_str());
				element.clear();
			}
		}else{
			element += buf[i];
		}
	}
	if(!element.empty())
		g_cmd_string[g_cmd_num++] = element;
}

void doLogin(const string& strName,const string& strPass){
	try{
		g_pClient = new CClient(strName,strPass);
	}catch(...){
		return;
	}
	g_pClient->connect();
}

void exec_cmd(){
	if(g_cmd_num == 0)
		return;
	if(g_cmd_string[0] == "login"){
		if(g_cmd_num == 3)
			doLogin(g_cmd_string[1],g_cmd_string[2]);

	}
}

void OnThreadRun(){
	char m_buf[MAX_LINE_LEN];
	while(1){
		if(fgets(m_buf,MAX_LINE_LEN-1,stdin) == NULL){
			continue;
		}
		m_buf[strlen(m_buf)-1] = '\0';
		split_cmd(m_buf);
		exec_cmd();
	}
}

int main(){
	OnThreadRun();

	return 0;
}
