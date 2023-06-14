#include <stdio.h>
/**
 * @brief  运算符、表达式和语句
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

#define ADJUST 7.31
int main(int argc, char const *argv[])
{
    
    const double SCALE = 0.333;
    double shoe, foot;
    shoe = 9.0;
    foot = SCALE * shoe + ADJUST;
    printf("Shoe size (men's) foot length\n");
    printf("%10.1f %15.2f inches\n", shoe, foot);
    return 0;
}
