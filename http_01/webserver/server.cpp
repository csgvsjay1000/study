#include "webserver.h"

int main(){
	WebServer ws;
	ws.ServerInit(12138);

	while(1){
		ws.ServerAccept();
	}

	return 0;
}
