#include <stdio.h>

#include <limits.h>

/**
 * 
 * MATLAB代码转换为C代码
 * 
*/

void addFun(int a, int b, int *c, int *d);

int main(int argc, char const *argv[])
{

    int c, d;

    addFun(1, 2, &c, &d);

    printf("Tst %d, %d", c, d);

    return 0;
}

void addFun(int a, int b, int *c, int *d)
{
    int i;
    double d0;
    for (i = 0; i < 10; i++)
    {
        d0 = (double)a + (1.0 + (double)i);
        if (d0 < 2.147483648E+9)
        {
            *c = (int)d0;
        }
        else
        {
            *c = INT_MAX;
        }

        d0 = (double)b + (1.0 + (double)i);
        if (d0 < 2.147483648E+9)
        {
            *d = (int)d0;
        }
        else
        {
            *d = INT_MAX;
        }
    }
}