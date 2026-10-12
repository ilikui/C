#include <stdio.h>
#define SIZE 50


/**
 * 
 */
void readlist(float list[], int n);


int main(void)
{
    
    float list[SIZE];

    readlist(list, SIZE);
    return 0;
}

/**
 * Reads a list of floating-point numbers from the user.
 * @param list The array to store the numbers.
 * @param n The number of elements to read.
 */
void readlist(float list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%f", &list[i]);
    }
}