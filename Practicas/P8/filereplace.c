#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define printDebug(...) do{\
    char *isDebug;\
    isDebug = getenv("DEBUG");\
    if(isDebug != NULL && !strcasecmp(isDebug, "y")){\
        fprintf(stderr, __VA_ARGS__);\
    }\
}while(0)

int main(){
    char*filename = "input.txt";
    FILE *input;
    char *search = "mundo";
    char *replace = "MUNDOMUNDO";
    char word[255];
    long searchpos = 0;
    input = fopen(filename, "r");
    while(1){
        fscanf(input, "%s", word);
        if(feof(input)){
            break;
        }
        if(strcmp(word, search) == 0){
            printDebug("Found %s\n", word);
            fseek(input, -1 * strlen(search), SEEK_CUR);
            searchpos = ftell(input);
            printDebug("searchpos = %d", searchpos);
            rewind(input);
            while(ftell(input) != searchpos){
                character = fgetc(input);
                fputc(character, stdout);
            }
        }
    }
}