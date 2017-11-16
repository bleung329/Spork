#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main{
  
  srand(time(NULL));

  int f = fork();

  printf("some initial message");

  if(f){
    printf("pid: %d", getpid());
    sleep(rand() % 15 + 5);
    printf("a message that it is finished");
  }
  else{
    if(f){
      printf("pid: %d", getpid());
      sleep(rand() % 15 + 5);
      printf("a message that it is finished");
    }
    else{
      int signal = 2;
      wait(&signal);
    }
  }
  return 0;
}
