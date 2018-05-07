#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int tweets[MAX_LENGTH];
int size = 0;
int numClicks = 0;
int numOpened = 0;
char tweet[256] = { 0 };


void getInstruction(char *);
void closeAll();
void addRemove(int *, int);
void countOpened(int *);

int main(){
    scanf("%i %i", &size, &numClicks);
    printf("Number of tweets: %i\n", size);
    printf("Number of clicks: %i\n", numClicks);
    fgets(tweet, 1, stdin);
    
    fgets(tweet, 1000, stdin);

    for(int i = 0; i < numClicks; i++){
        fgets(tweet, 1000, stdin);
        getInstruction(tweet);
    }
}

void getInstruction(char *sentence){
    char *str = sentence;
    char *token;
    token = strtok (str," ,.-\n");
   
    while (token != NULL){
        if(strcmp(token,"CLOSEALL") == 0){
            closeAll();
            printf("%i\n", numOpened);
        }
        else if(strcmp(token, "CLICK") == 0){
            token = strtok (NULL, " ,.-\n");
            int index = atoi (token);
            addRemove(tweets, index);
            printf("%i\n", numOpened);

        }
        token = strtok (NULL, " ,.-\n");
    }
}

void closeAll(){
    for(int i = 0; i < size; i++){
        tweets[i] = 0;
        numOpened = 0;

    }
}

void addRemove(int *tweets, int index){
    if(tweets[index] == 0){
        tweets[index] = 1;
        numOpened++;

    }
    else{
        tweets[index] = 0;
        numOpened--;
    }
}

void countOpened(int *tweets){
    int temp = 0;
    for(int i = 0; i < size; i++){
        printf("%i: %i\n",i, tweets[i]);
        if(tweets[i] == 1){
            temp++;
            printf("Temp: %i\n", temp);

        }
    }
    numOpened = temp;
}
