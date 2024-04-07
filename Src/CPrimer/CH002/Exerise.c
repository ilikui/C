#include <stdio.h>

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const *argv[])
{

    char a = 'a';
    char b = 'b';

    char A = 'A';

    char B = 'B';

    printf("%c ,%c,%c,%c\n",a,b,A,B);
    printf("a = %d ,b = %d,A= %d,B= %d\n",a,b,A,B);

    getchar();

    putchar(getchar()+32);


    return 0;
}
