#include "reader.h"
void read_buffer(char buffer[],char *words[],int *words_count){
int i=0;
words[i]=buffer;
(*words_count)++;
while(buffer[i] != '\0'){
    if(buffer[i] == ' '){
        buffer[i]='\0';
        words[*words_count]=&buffer[i+1];
        (*words_count)++;
    }
    i++;
}
}