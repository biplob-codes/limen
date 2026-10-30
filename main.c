#include <stdio.h>
#include <string.h>
#include "reader.h"
int main(){
    printf("Welcome to limen shell!!!\n");
    char buffer[256];
    while(1){
        printf("$$$: ");
        if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
        buffer[strcspn(buffer,"\n")]='\0';
        int word_count=0;
        char *words[10];
        read_buffer(buffer,words,&word_count);
        for(int i=0;i < word_count;i++){
        printf("At index: %d we have : %s\n",i,words[i]);
        }
        }
        else{
            printf("Something went wrong\n");
            return 1;
        }
    }
    return 0;
}