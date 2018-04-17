#include <stdio.h>
#include <omp.h>
#define SIZE 20000
//export OMP_NUM_THREADS=400
int main(){

    int a[SIZE];
    int b[SIZE];
    int c[SIZE];

    for(int i = 0; i < SIZE; i++){
        a[i] = i;
        b[i] = 2*i;

    }

    #pragma omp parallel{
        for(int j = 0; j < SIZE; i++){
            c[j] = a[j] + b[j];
        }
    }
    return 0;
}