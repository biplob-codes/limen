#include <stdio.h>
#include <string.h>
int main(){
    printf("Welcome to limen shell!!!\n");
    char buffer[256];
    while(1){
        printf("$$$: ");
        if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
        buffer[strcspn(buffer,"\n")]='\0';
        int i=0;
        int word_count=0;
        char *words[10];
        words[i]=buffer;
        word_count++;
        while(buffer[i] != '\0'){
            if(buffer[i]==' '){
                buffer[i]='\0';
                words[word_count]=&buffer[i+1];
                word_count++;
            }
            i++;
        }
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