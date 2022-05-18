#include <stdio.h>

int main(int argc, char const *argv[])
{
    int var_name = 10;

    int *p;
    p = &var_name;
    
    printf("varname = %p\n",p);
    return 0;
}
