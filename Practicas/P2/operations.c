#include <assert.h>
#include "operations.h"
#define MAX_INT 2147483647

/**
 * Use long addition to catch overflow 
 */

int add(int a, int b){
    
    // Do the addition and check if there is an overflow
    // Compare with 2147483647, the maximum int value in C

    long c = (long) a + b;

    assert( c < MAX_INT && c > -MAX_INT);

    return (int) c;
}

/**
 * Use long addition to catch overflow 
 */

int substract(int a, int b){

    // Do the substraction and check if there is an overflow
    // Compare with 2147483647, the maximum int value in C

    long c = (long) a - b;

    assert( c < MAX_INT && c > -MAX_INT);

    return (int) c;

}