#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

//write a c program that does the following
int main() {
	
	//parent: before forking, print some initial msg
	printf("begin forking: \n");
	//forks off 2 child processes
	int c1, c2;
	c1 = fork();
	if(c1) c2 = fork();

	//after fork, wait for child to finish
	if(c1 && c2) {
		int status;
		//once child has finsihed, print pid of compeleted child and how many seconds it was asleep for (dont use timer, think how child cld send this info back to parent)
		printf("child process %d slept for %d seconds\n", wait(&status), WEXITSTATUS(status));
		//print msg that parent is done and end the program
		printf("parent process has finished\n");
		return 0;
	}else{
		//at start print its pid
		printf("child process %d starting\n", getpid());
		//sleep for random number of seconds in range [2,5]
		int time = (rand() % 4) + 2;
		//each child should sleep for a potentially diff amt of seconds
		sleep(time);
		//at end print msg that it is finished
		printf("child process has finished\n");
		return time;
	}
	return 0;
}
