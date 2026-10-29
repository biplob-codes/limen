#include <stdio.h>
#include <string.h>
int main(){
    printf("Welcome to limen shell!!!\n");
    char buffer[256];
    while(1){
        printf("$$$: ");
        if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
        buffer[strcspn(buffer,"\n")]='\0';
        printf("You typed: %s\n",buffer);
        }
        else{
            printf("Something went wrong\n");
            return 1;
        }
    }
    return 0;
}