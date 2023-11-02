#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int *zPtr; /* zPtr will reference array z */
    int *aPtr = NULL;
    void *sPtr = NULL;
    int number, i;
    int z[ 5 ] = { 1, 2, 3, 4, 5 };
    zPtr = z;
    sPtr = z;

    // a)
    /* use a pointer to get the first value of the array */
    number = *zPtr;
    printf("The first value of the array z is: %d\n", number);

    // b)
    /* assign array element 2 (the value 3) to number */
    number = zPtr[2];
    printf("The value at index 2 of the array z is: %d\n", number);

    // c)
    /* print the entire array z */
    printf("The entire array z: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", zPtr[i]);
    }
    printf("\n");

    return 0;
}