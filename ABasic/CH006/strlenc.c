#include <stdio.h>

#include <stdlib.h>


/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */


size_t strlen(char * string);
int main(int argc, char const *argv[])
{
    
    char  a[] = "hello world";

   

     printf("String length: %d",strlen(a));

    return 0;
}

size_t strlen(char * string)
{

        int length = 0;

        while (*string ++ != '\0')
        {
            length += 1;
        }


        return length;
        


}
