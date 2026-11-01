#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
void execute(char *commands[]){
if(strcmp(commands[0],"cd")==0){
   char *dir=commands[1] ? commands[1]:getenv("HOME");
   if(dir==NULL){
      dir="/";
   }
   if (chdir(dir)!=0){
      perror("cd");
      return;
   }
   return;
}
else if(strcmp(commands[0],"exit")==0){
   exit(0);
}
else{
    pid_t pid=fork();
 if (pid <0){
    perror("fork failed");
    exit(1);
 }
 if(pid==0){
    execvp(commands[0],commands);
    perror("execv failed");
    exit(1);
 }
 else{
    wait(NULL);
 }
}

}