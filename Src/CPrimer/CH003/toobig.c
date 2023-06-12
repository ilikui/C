#include <stdio.h>

/**
 * @brief 大数测试
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    int i =  2147483647;
    unsigned int j = 4294967295;

    printf("%d %d %d",i,i+1,i+2);
    printf("%u %u %u",j,j+1,j+2);

    return 0;
}

/**
 * @brief 
 * 2147483647 -2147483648 -21474836474294967295 0 1
 * 
 */