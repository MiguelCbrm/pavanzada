#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strongPasswordChecker(char *);
int checkLen(char *);
int charChecker(char *);
int checkSequence(char *);


int main(){
    char *password = "Password";
    strongPasswordChecker(password);
    return 0;
}

int strongPasswordChecker(char *s) {
    checkLen(s);
    charChecker(s);
    checkSequence(s);
    return 1;
}

int checkLen(char *psw){
    if(strlen(psw) >=6 && strlen(psw) <=20){
        printf("First rule passed.\n");
        return 0;
    }
    
    printf("First rule failed.\n");
    return 1;
}

int charChecker(char *psw){
    for(int i = 0; i < strlen(psw); i++){
        if(islower(psw[i])){
            printf("It has lower case.\n");
            break;
        }
    }

     for(int i = 0; i < strlen(psw); i++){
        if(isupper(psw[i])){
            printf("It has upper case.\n");
            break;
        }
    }

    for(int i = 0; i < strlen(psw); i++){
        if(isdigit(psw[i])){
            printf("It has digits.\n");
            break;
        }
    }
    return 0;
}

int checkSequence(char *psw){
    int count = 0;
    for(int i = 0; i < strlen(psw); i++){
        char temp = psw[i];
        count = 0;
        for(int j = 0; j < strlen(psw); j++){
            if(temp == psw[j]){
                count ++;
                if (count == 3){
                    printf("Rule 3 failed\n");
                    return -1;
                }
            }
        }
    }
    printf("Third rule Passed.\n");
    return 0;
}
