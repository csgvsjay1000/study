#ifndef __PROCESSPOOL_H__
#define __PROCESSPOOL_H__


#include <stdio.h>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

using std::vector;

class process{
	public:
		process():m_pid(-1){}

		int m_busy_ratio;
		pid_t m_pid;
		int m_pipefd[2];
};

template<typename C,typename H,typename M>

class processpool{
	private:
		processpool(int listenfd,int process_number = 8);
	public:
		static processpool<C,H,M>* create(int listenfd,int process_number = 8){
			if(!m_instance){
				m_instance = new processpool<C,H,M>(listenfd,process_number);
			}
			return m_instance;
		}
		void run(const vector<H>& arg);	
	private:
		static processpool<C,H,M>* m_instance;
		process* m_sub_process;
		int m_idx;
};

template< typename C, typename H, typename M >
processpool< C, H, M >* processpool< C, H, M >::m_instance = NULL;


	
template< typename C, typename H, typename M >
processpool< C, H, M >::processpool( int listenfd, int process_number  ){
	m_sub_process = new process[ process_number  ];
	assert( m_sub_process  );
	for( int i = 0; i < process_number; ++i  ){
		int ret = socketpair( PF_UNIX, SOCK_STREAM, 0, m_sub_process[i].m_pipefd  );
		assert( ret == 0  );
		m_sub_process[i].m_pid = fork();
		assert( m_sub_process[i].m_pid >= 0  );
		if( m_sub_process[i].m_pid > 0  ){
			close( m_sub_process[i].m_pipefd[1]  );
			m_sub_process[i].m_busy_ratio = 0;
			continue;
		}else{
			close( m_sub_process[i].m_pipefd[0]  );
			m_idx = i;
			break;
		}
	}
}

void processpool< C, H, M >::run( const vector<H>& arg  ){

}

#endif
