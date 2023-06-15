#include <stdio.h>

int main(int argc, char const *argv[])
{
    int status;

    int num;
    printf("Please input a number:\n");
    status = scanf("%d", &num);
    while (status == 1)
    {
        printf("Please input a number:\n");
        status = scanf("%d", &num);
        if (1 != status)
        {
           break;
        }
        
    }
    
    printf("%d\n", status);
    return 0;
}
