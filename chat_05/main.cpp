#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <vector>

#include "log.h"
#include "mgr.h"
#include "processpool.h"
#include "conn.h"

using std::vector;

static const char *version = "1.0";

int main(int argc,char* argv[]){
	
	host balance_srv;	
	//balance_srv.m_hostname = "192.168.200.85";
	vector<host> logical_srv;
	host tmp_host;
	memcpy(tmp_host.m_hostname,"192.168.200.85",sizeof(tmp_host.m_hostname));
	tmp_host.m_port = 13579;
	tmp_host.m_conncnt = 5;
	logical_srv.push_back(tmp_host);
	memset(tmp_host.m_hostname,'\0',sizeof(tmp_host.m_hostname));
	
	memcpy(tmp_host.m_hostname,"192.168.200.85",sizeof(tmp_host.m_hostname));
	tmp_host.m_port = 13589;
	tmp_host.m_conncnt = 5;
	logical_srv.push_back(tmp_host);
	

	const char *ip = "192.168.200.85";
	int port = 12345;
	int listenfd = socket( PF_INET, SOCK_STREAM, 0  );
	assert( listenfd >= 0  );
	
	int ret = 0;
	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	inet_pton( AF_INET, ip, &address.sin_addr  );
	address.sin_port = htons( port  );
	ret = bind( listenfd, ( struct sockaddr*  )&address, sizeof( address  )  );
	assert( ret != -1  );
	ret = listen( listenfd, 5  );
	assert( ret != -1  );
	
	processpool<conn,host,mgr>* pool = processpool<conn,host,mgr>::create(listenfd,logical_srv.size());
	if(pool){
		pool->run(logical_srv);
	}

	close(listenfd);

	return 0;
}
