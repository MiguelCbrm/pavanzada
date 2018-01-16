#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int doFullName(char *firstName, char *lastName, char **fullName){
	
    int sizeFName  = strlen(firstName);
    int sizeLName = + strlen(lastName);
    
    *fullName = (char * )malloc((sizeFName + sizeLName + 1)* sizeof(char));
   
    strcpy(*fullName, firstName);
    strcpy(*fullName + sizeFName, " ");
    strcpy(*fullName +sizeFName + 1, lastName);
    
    return 0;
}

int main (){

    char firstName [] = "Miguel";
    char lastName [] = "Cabral";
    char *fullName;
    
    doFullName(firstName, lastName, &fullName);
    printf("Full Name: %s\n", fullName);
    free(fullName);
    
    return 0;
}