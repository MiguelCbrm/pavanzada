#include <stdio.h>
#include <ctype.h>
#include <string.h>

int numE = 0;
int numP = 0;

void validateNum(char *);
int isDigit(char *);

int main(){
    validateNum("12,123");
    validateNum("12.123");
    validateNum("12.0e123");
    validateNum("12.0e12.3");
    validateNum("12.0 12.3");
    validateNum("12,12,3");
    validateNum("12.12.3");
    validateNum("120e.123");
    validateNum("12.e12.3");
}

void validateNum(char *num){
    isDigit(num);
}

int isDigit(char *num){
    numE = 0;
    numP = 0;
    for(int i = 0; i < strlen(num); i++){

        if(isalpha(num[i]) && num[i] != 'e'){
            printf("false, letter not recognized\n");
            return -1;
        }
        else if(isblank(num[i])){
            printf("false, blank spaces aren't allowed\n");
            return -1;
        }
        else if (num[i] == 'e'){
            if(numE < 1){
                numE++;
            }
            else{
                printf("false, more than one 'e'\n");
                return -1;
            }
        }
        else if(num[i] == '.'){
            if(i == 0){
                printf("false, a digit is needed before the '.'\n");
                return -1;
            }
            else if(i == strlen(num) - 1){
                printf("false, '.' can't be placed at the end\n");
                return -1;
            }
            else if( num[i - 1] == 'e' || num[i + 1] == 'e'){
                printf("false, a digit is needed between the 'e' and the '.'\n");
                return -1;
            }
            else if(numP < 1 && numE == 0){
                numP = 1;
            }
            else if ( numP < 1 && numE == 1){
                numP = 2;
            }
            else if(numP == 1 && numE == 1){
                numP = 2;
            }
             else if(numP == 1 && numE == 0){
                printf("false, number of '.' exceeded\n");
                return -1;
            }
            else if (numP == 2){
                printf("false, number of '.' exceeded\n");
                return -1;
            }
        }
        else if(num[i] == ','){
            if(i >= (strlen(num) - 3) || i == 0){
                printf("false, ',' isn't well placed\n");
                return -1;
            }
            else{
                if(!isdigit(num[i + 1]) || !isdigit(num[i + 2]) || !isdigit(num[i + 3])){
                    printf("false, at least one ',' isn't well placed\n");
                    return -1;
                }
            }
        }

    }
    printf("true\n");
    return 1;
}