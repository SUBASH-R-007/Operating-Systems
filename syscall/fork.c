#include<stdio.h>
#include<unistd.h>
int main(){
	//child process
	if(fork()==0){
		printf("This is Child process");
	}
	//parent process
	else{
		printf("This is parent process");
	}
	//fork();
	//fork();
	//fork();
	printf("PID: %d\n",getpid());
	return 0;
}

