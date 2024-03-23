#include <stdio.h>

#define MONTHS 12

int main(int argc, char const *argv[])
{
    
    int days[MONTHS] = {31,25,28,30,29,30,31,29,24,31,30,30};
    int index;


    for (index = 0; index < MONTHS; index++)
    {
        printf("Month %2d has %2d days.\n",index+1,days[index]);
    }
    
    

    return 0;
}
