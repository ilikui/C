#include <stdio.h>



/**
 * Prints the sizes of basic data types.
 */
void printfsizeof(void);

int main(void)
{
   
    printfsizeof();
    return 0;
}

/**
 * @brief Prints the sizes of basic data types.
 */
void printfsizeof(void)
{
    printf("Size of int: %zu\n", sizeof(int));
    printf("Size of char: %zu\n", sizeof(char));
    printf("Size of double: %zu\n", sizeof(double));
    printf("Size of void*: %zu\n", sizeof(void*));
}


/**
 * @brief Entry point of the program. Calls printfsizeof() to print the sizes of basic data types.
 * @return int Exit status of the program.
 * Size of int: 4
 * Size of char: 1
 * Size of double: 8
 * Size of void*: 4
 */