#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"

/**
 * @brief Demonstrates dynamic memory allocation and spinning in a loop.
 *
 * This program allocates an integer on the heap, continuously increments it,
 * and prints its value along with the process ID every second. It uses the
 * Spin function to create a delay.
 */
int main() {

    int *p = malloc(sizeof(int)); //a1

    assert(p != NULL);
    printf("(%d) memory address of p: %p\n",getpid(), (void *)p); //a2

    *p = 0;
    while (1) {
        Spin(1);
        *p  = *p + 1;
        printf("(%d) current value of *p: %d\n", getpid(), *p);
    }
    free(p);
    return 0;
}