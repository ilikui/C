#include <stdio.h>
#include <string.h>


#define PRAISE "You are an extraordinary being."
int main(int argc, char const *argv[])
{
    char name[40];
    printf("What's your name?");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %d letters occupies %d memory cells.\n", strlen(name), sizeof name);
    printf("The phrase of praise has %d letters ", strlen(PRAISE));
    printf("and occupies %d memory cells.\n", sizeof PRAISE);
    printf("The size of int is %d", sizeof(int));
    return 0;
}
