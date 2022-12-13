#include <stdio.h>

void fun1(void)
{

    int i = 0;
    i++;
    i = i*2;
    printf("%d\n",i);
}


void fun2(void)
{
    int j = 0;
    fun1();

    j++;
    j = j*2;

    printf("%d\n",j);


}

int main(int argc, char const *argv[])
{

    fun2();
    
    return 0;
}
