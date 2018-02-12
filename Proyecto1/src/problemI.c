#include "uthash.h"
#include <stdlib.h>   
#include <stdio.h>    

/*
UTHASH implementada por:
Copyright (c) 2008-2017, Troy D. Hanson   http://troydhanson.github.com/uthash/
All rights reserved.
*/

typedef struct diccionary {
    int a;
    int b;
    UT_hash_handle hh;
} diccionary;

diccionary *translation, *tmp, *translations=NULL;
int numTranslations;
int numWords;
char charA;
char charB;
char wordA[50];
char wordB[50];

int addToHash(char, char);
char findElement(char);
void printHash();
int ruleOne(char *, char *);
int ruleTwo(char *, char *);
int compareWords(char *, char *);

int main(int argc,char *argv[])
{

    scanf("%d %d\n", &numTranslations, &numWords);
    
    for (int i = 0; i < numTranslations; i++){
        scanf("%c %c\n", &charA, &charB);
        addToHash(charA, charB);
    }

    printHash();

    for(int i = 0; i < numWords; i++){
        scanf("%s %s\n", wordA, wordB);
        compareWords(wordA, wordB);
    }

}

int addToHash(char a, char b)
{
    /* create elements */
    translation = (diccionary*)malloc(sizeof(diccionary));
    translation->a = a;
    translation->b = b;
    HASH_ADD_INT(translations,a,translation);

    return 0;
}

char findElement(char a)
{
    /* find each even ID */
    HASH_FIND_INT(translations,&a,tmp);
    if (tmp != NULL) {
        printf("user id %d found, cookie %d\n", tmp->a, tmp->b);
    } else {
        printf("user id %c not found\n", a);
        return '-';
    }
    return tmp->b;
}

void printHash(){
   
    for(translation=translations; translation != NULL; translation=(diccionary*)(translation->hh.next)) {
        printf("a: %c, b: %c\n", translation->a, translation->b);
    }
}

int ruleOne(char *wordOne, char*wordTwo){
    
    if(strlen(wordOne) == strlen(wordTwo)){
        return 1;
    }
    return 0;
}

int ruleTwo(char *wordOne, char*wordTwo){
    for(int i = 0; i < strlen(wordOne); i++){
        if(wordOne[i] != wordTwo[i]){
            if(findElement(wordOne[i]) != wordTwo[i]){
                //printf("different\n");
                return 0;
            }
        }
    }
    return 1;
}

int compareWords(char *wordOne, char*wordTwo){
    if (ruleOne(wordOne, wordTwo) == 1){
        //printf("Rule One passed\n");
        if(ruleTwo(wordOne, wordTwo) == 1){
            //printf("Rule Two passed\n");
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
    return 0;
}
