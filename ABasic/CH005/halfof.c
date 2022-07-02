
/**
 * @file halfof.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

float x = 3.5,y =65.11,z;

float half_of(float k);  //函数里面的时形式参数
int main(int argc, char const *argv[])
{

    z = half_of(x);
    //本次调用中，x是half_of()的实参
    printf("The value of z = %f\n",z);
    //本次调用中，y是half_of()的实参
    z = half_of(y);
     
    printf("The value of z = %f\n",z);
    //本次调用中，z是half_of()的实参
     z = half_of(z);
     printf("The value of z = %f\n",z);
    return 0;
}


float half_of(float k)
{
    return (k/2);
}



