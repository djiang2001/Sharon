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
  char input[256];
  char input2[256];

  key = ftok("/somefile", 'R');
  shmid = shmget(key,200,0644 | IPC_CREAT);
  data = shmat(shmid,(void*)0,0);
  
  if(!data[0]){
    printf("Recently created shared memory \n");
  }else{
    printf("Shared content: %s \n", data);
  }
    
  printf("Do you want to change data? (y/n) \n");
  fgets(input,256,stdin);
    
  if(!strcmp(input,"y\n")){
    printf("Input your new string: \n");
    fgets(input,200,stdin);
    data[strlen(input) - 1] = 0;
    strcpy(data,input);
  }
  printf("Shared memory content: %s \n", data);
  
  printf("Do you want to delete a segment? (y/n) \n");
  fgets(input2,256,stdin);
  
  if(!strcmp(input2,"y\n")){
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    printf("Segment deleted \n");
  }

  return 0;
}
