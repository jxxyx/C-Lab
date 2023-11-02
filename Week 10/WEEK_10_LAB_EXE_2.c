#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
    long value1 = 200000;
    long value2;

    // a) Define the variable lPtr to be a pointer to a variable of type long
    long *lPtr;

    // b) Assign the address of variable value1 to pointer variable lPtr
    lPtr = &value1;

    // c) Print the value of the variable pointed to by lPtr
    printf("%ld\n", *lPtr);

    // d) Assign the value of the variable pointed to by lPtr to variable value2
    value2 = *lPtr;

    // e) Print the value of value2
    printf("%ld\n", value2);

    // f) Print the address of value1
    printf("%p", &value1);

    // g) Print the address stored in lPtr. Is the value printed the same as the address of value1?
    printf("%p\n", lPtr);

    return 0;

}