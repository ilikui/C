#include <stdio.h>

#define PRAISE "You are an extraordinary being."
int main(int argc, char const *argv[])
{
    char name[40];

    printf("What's your name? \n");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    return 0;
}
