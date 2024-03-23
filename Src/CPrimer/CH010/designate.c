#include <stdio.h>
#define MONTHS 12

int main(int argc, char const *argv[])
{

    int daya[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    int index;
    for (index= 0; index < MONTHS; index++)
    {
       printf("%2d   %d\n",index+1,daya[index]);
    }
    
    return 0;
}
