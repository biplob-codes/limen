#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
void execute(char *commands[]){
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