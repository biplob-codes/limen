#include <stdlib.h>
#include "parser.h"
void parse_buffer(char buffer[],char *commands[],int max_size){
char *words[max_size-1];
int count=0;
int i=0;
words[i]=buffer;
count++;

while(buffer[i] != '\0'){
    if(buffer[i] == ' '){
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
}