#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
#include "execute.h"
#define MAX_ARGS 64
int last_status=0;
int main(){
    printf("Welcome to limen shell!!!\n");
    char buffer[256];
    while(1){
        printf("\n$$$: ");
        if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
        buffer[strcspn(buffer,"\n")]='\0';
        char *commands[MAX_ARGS];
        int result=parse_buffer(buffer,commands,MAX_ARGS);
        if(result >0) continue;
        execute(commands,&last_status);
        }else if(feof(stdin)){
            printf("\n");
            exit(0);
        }else{
            fprintf(stderr,"something went wrong while taking input\n");
            exit(1);
        }
    }
    return 0;
}