#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  key_t key;
  int shmid;
  char * data;
  char * input;

  key = ftok("/home/somefile", 'R');
  shmid = shmget(key,200,0644 | IPC_CREAT);
  data = shmat(shmid,(void*)0,0);
  
  if(data){
    printf("Recently created shared memory \n");
  }else{
    printf("Shared content: %s \n", data);
  }

  while(
  printf("Do you want to change data (y/n)? \n");
  scanf("%c", &input);

  if(strcmp(input,"y")){
    printf("Input your string \n");
  }else{
    printf("Do you want to delete data (y/n)? \n");
    scanf("%c",&input);

    if(strcmp(input,"y"){

      }
      
  }
  return 0;
}
