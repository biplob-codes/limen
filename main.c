#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "execute.h"
#define MAX_ARGS 64
int main(){
    printf("Welcome to limen shell!!!\n");
    char buffer[256];
    while(1){
        printf("\n$$$: ");
        if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
        buffer[strcspn(buffer,"\n")]='\0';
        char *commands[MAX_ARGS];
        parse_buffer(buffer,commands,MAX_ARGS);
        execute(commands);
        }
        else{
            printf("Something went wrong\n");
            return 1;
        }
    }
    return 0;
}