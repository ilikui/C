#include <stdio.h>

#include <stdint.h>

int main(int argc, char const *argv[])
{
   int8_t a = 0xA5;

   int8_t b = 0;

   char status = 0;

  do
  {
    
   printf("Pls enter the data: ");

   scanf("%x",&b);

   printf("b = %d\n",b);
   
  } while ('q' != status);
  
   

    return 0;
}

