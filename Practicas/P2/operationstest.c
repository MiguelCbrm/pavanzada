#include <stdio.h>
#include "operations.h"

void printTestMessage(int, char *, char *);
int testAddition(void);
int testSubstraction(void);

int main (){
    //Add method test

    printTestMessage(testAddition(), "Add test passed", "Add test failed");    

    //Substraction method test

    printTestMessage(testSubstraction(), "Substraction test passed", "Substraction test failed");    

    return 0;
}

/**
 * Prints the test message, asks for condition and both messages
 */
void printTestMessage(int condition, char *messagePassed, char *messageFailed){

    if(condition){
        printf("%s\n", messagePassed);
    }
    else{
        printf("%s\n", messageFailed);
    }
}

int testAddition(){
    //Add method test

    int a = 2;
    int b = 3;

    int resultAdd = add(a, b);
    int expectedAdd = a + b;

    return resultAdd == expectedAdd;
}

int testSubstraction(){
   //Substraction method test

    int c = 2;
    int d = -3;

    int resultSubstract = substract(c, d);
    int expectedSubstract = c - d;

    return resultSubstract == expectedSubstract;
}