#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
void execute(char *commands[],int *last_status){
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
   if(commands[1]!=NULL && strcmp(commands[1],"$?")==0){
   char buf[32];
   int result=snprintf(buf,sizeof(buf),"%d",*last_status);
   if(result<0 || result>=(int)sizeof(buf)){
      perror("converstion to string failed for last status");
      exit(1);
   }
   commands[1]=buf;
}
    execvp(commands[0],commands);
    perror("execv failed");
    exit(127);
 }
 else{
   int status;
   pid_t waited=waitpid(pid,&status,0);
   if(waited<0){
      perror("waitpid");
      exit(1);
      }
   if(WIFEXITED(status)){
      *last_status=WEXITSTATUS(status);

   }
   else if(WIFSIGNALED(status)){
      *last_status=WTERMSIG(status)+128;
   }

 }
}

}