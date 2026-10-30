#include <stdlib.h>
#include "parser.h"
void parse_words(char *words[],char *commands[],int word_count){
    int i;
    for(i=0;i<word_count;i++){
        commands[i]=words[i];
    }
    commands[i]=NULL;
}