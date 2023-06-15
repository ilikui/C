#include <stdio.h>

/**
 * @brief 逗号运算符
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    const int FIRST_OZ =46;
    const int MEXT_OZ = 20;
    int ounces, cost;
    printf(" ounces cost\n");
    for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += MEXT_OZ)
    {
        printf("%5d $%4.2f\n", ounces, cost / 100.0);
    }
    
    return 0;
}
