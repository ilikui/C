#include <stdio.h>
#include <string.h>

/**
 * @brief 字符串的使用
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
#define DENSITY 62.4
int main(int argc, char const *argv[])
{
    
    float wightt, volume;

    int size,letters;

    char name[40];
    printf("Hi, What's your first name?\n");
    scanf("%s",name);

    printf("%s, What's your weight in pounds?\n",name);
    scanf("%f",&wightt);
    size = sizeof name;
    letters = strlen(name);
    volume = wightt / DENSITY;    
    printf("Well, %s, your volume is %2.2f cubic feet.\n",name,volume);
    printf("Also, your first name has %d letters,\n",letters);
    return 0;
}
