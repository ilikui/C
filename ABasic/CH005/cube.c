/**
 * @file cube.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include <stdio.h>

long cube(long x);

long input,answer;

int main(int argc, char const *argv[])
{
    printf("Enter an integer value: ");
    scanf("%ld",&input);
    answer = cube(input);

    printf("\n The cube of %ld is %ld\n",input,answer);
    return 0;
}


long cube(long x)
{
    long x_cubed;

    x_cubed = x * x *x;

    return x_cubed;
}
