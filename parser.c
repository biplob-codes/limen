#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
int parse_buffer(char buffer[],char *commands[],int max_size){
char *words[max_size-1];
int count=0;
int i=0;
words[i]=buffer;
count++;

while(buffer[i] != '\0'){
    if(buffer[i] == ' '){
        if(count==(max_size-1)){
            printf("too many arguments");
            return 1;
        }
        buffer[i]='\0';
        words[count]=&buffer[i+1];
        count++;
    }
    i++;
}
int j=0;
for (j=0;j<count;j++){
commands[j]=words[j];
}
commands[j]=NULL;
return 0;
}