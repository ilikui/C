#include <stdio.h>
/**
 * @brief 注意不要使用无限循环
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char const *argv[])
{
    int n =0;
    while (n<3)
    {
        printf("n is %d\n",n);
        n++;
    }
    printf("That's all this program does\n");
    
    
    return 0;
}
