#include <stdio.h>

/**
 * @brief 几种常见的语句
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    int count ,sum;
    count = 0;
    sum = 0;
    while (count++ < 10)
    {   
        sum = sum + count;
    }
    printf("sum = %d\n", sum);
    return 0;
}
