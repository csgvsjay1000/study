#include <stdio.h>
#include <thread>
#include <unistd.h>

using namespace std;

void do_some_work(){
	for(int i=0;i<10;i++){
		sleep(1);
		printf("do_some_work std \n");
	}
}

class background_task{
public:
	void operator()() const{
		do_some_work();
	}
};

int main(){

	background_task task;
	thread my_thread(task);
	my_thread.detach();
	//my_thread.join();
	printf("****************************\n");
	return 0;
}
