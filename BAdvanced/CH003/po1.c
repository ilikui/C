#include <stdio.h>

#include <stdlib.h>


/**
 * 
 * 统计字符串的长度
*/


size_t  strlen(char *string)
{
    int length= 0;

    while(*string++  != '\0')
    {

        length++;

    }

    return length;

}
int main(int argc, char const *argv[])
{
    /* code */

    printf("the length: %d\n",strlen("Hello"));
    return 0;
}
