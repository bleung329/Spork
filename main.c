#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){

	printf("some initial message\n");

  	int f = fork();

  	if(!f){
		printf("child pid: %d\n", getpid());
		srand(getpid());
		int sleepytime = rand() % 15 + 5;
		sleep(sleepytime);
		printf("a message that it is finished\n");
		exit(sleepytime);
  	}
  	else{
		int f = fork();
		if(!f){
		  	printf("pid: %d\n", getpid());
			srand(getpid());
			int sleepytime = rand() % 15 + 5;
		  	sleep(sleepytime);
		  	printf("a message that it is finished\n");
			exit(sleepytime);
		}
		else{
		  	int sleepytime;
		  	f = wait(&sleepytime);
			if(WIFEXITED(sleepytime)){
				sleepytime = WEXITSTATUS(sleepytime);
			}
			printf("My child with id %d, whomst'd've goes to Stuyvesant High School, slept for %d seconds\n", f, sleepytime);
			printf("I'm off to sue Stuyvesant High School, goodbye!\n");
			exit(0);
		}
  	}
  return 0;
}
