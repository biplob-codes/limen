#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "parser.h"
int parse_buffer(char buffer[],char *commands[],int max_size){
char *words[max_size-1];
int count=0;
int i=0;
int outside=1;
int inside=0;
while(buffer[i] != '\0'){
    if(!isspace(buffer[i]) && outside==1){
        if(count==(max_size-1)){
        printf("too many arguments");
        return 1;
       }
        words[count]=&buffer[i];
        count++;
        outside=0;
        inside=1;
    }
    if(isspace(buffer[i]) && inside==1){
        buffer[i]='\0';
        inside=0;
        outside=1;
    }
    i++;
}
if (count ==0) return 1;
int j=0;
for (j=0;j<count;j++){
commands[j]=words[j];
}
commands[j]=NULL;
return 0;
}