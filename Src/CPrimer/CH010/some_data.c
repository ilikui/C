#include <stdio.h>

/**
 * @brief 计算some data
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

#define SIZE 4
int main(int argc, char const *argv[])
{
    int some_data[SIZE] = {1492,1066};

    int i;
    printf("%2s%14s\n","i","spme_data[i]");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%2d%14d\n",i,some_data[i]);
    }
    
    return 0;
}
