#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "reader.h" 
#include "parser.h"

int main(){
    printf("Welcome to limen shell!!!\n");
    char buffer[256];
    while(1){
        printf("$$$: ");
        if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
        buffer[strcspn(buffer,"\n")]='\0';
        int word_count=0;
        char *words[10];
        char *commands[word_count+1];
        read_buffer(buffer,words,&word_count);
        parse_words(words,commands,word_count);
        for(int i=0;i < word_count;i++){
        printf("At index: %d we have : %s\n",i,commands[i]);
        }
        }
        else{
            printf("Something went wrong\n");
            return 1;
        }
    }
    return 0;
}