#include <stdio.h>
#include <signal.h>

void receiveSignal(int sig){
    printf("HOLA MUNDO \n");
    printf("Recibi señal %d\n", sig);

}

int main(){
    signal(SIGTERM, receiveSignal);
    while(1){

    }
    return 0;
}