#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 2048

char *words[100];
int indice = 0;

void print();

int main( int argc, char** argv ){

    const char *delimiter_characters =" \t\r\n\v\f";
    const char *filename = "sample1.txt";
    //const char *filename = "sample2.txt";
    //const char *filename = "sample3.txt";
    FILE *input_file = fopen( filename, "r" );
    char buffer[ BUFFER_SIZE ];
    char *last_token;

    if( input_file == NULL ){
        fprintf( stderr, "File not found: %s\n", filename);
    }

    else{
        while( fgets(buffer, BUFFER_SIZE, input_file) != NULL ){
            last_token = strtok( buffer, delimiter_characters );
            
            while( last_token != NULL ){
                words[indice] = last_token;
                indice++;
                last_token = strtok( NULL, delimiter_characters );
            }

            print();
            char *words[100];
            indice = 0;
        }

        fclose( input_file );
    }
    return 0;
}

void print(){
    for(int i = indice - 1; i >= 0; i--){
        printf("%s ", words[i]);
    }
    printf("\n");
}