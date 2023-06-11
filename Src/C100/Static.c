#include <stdio.h>

#define INVALEDVALE 255U

int main(int argc, char const *argv[])
{

    static value;

    int data =1;

   

    if(value  != data )
    {
         value =INVALEDVALE;
    }

    printf("%d", INVALEDVALE);

    return 0;
}
