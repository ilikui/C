#include <stdio.h>

/**
 * @brief 进制的使用
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    int x  = 100;

    printf("dec = %d; octal = %o;hex = %x\n",x,x,x);
    printf("dec = %d; octal = %#o;hex = %#x\n",x,x,x);

    return 0;
}
