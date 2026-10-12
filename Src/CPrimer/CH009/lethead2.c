
#include <stdio.h>
#include <string.h>

#define NAME "GIGATHINK, INC"
#define ADDRESS "123 Main Street"
#define PLACEHOLDER "Some Placeholder"
#define WIDTH   40

#define SPACE   " "


void show_n_chars(char ch, int n);

int main(void)
{
    /* code */
    int spaces = 0;
    show_n_chars('*', WIDTH);


    putchar('\n');

    show_n_chars(SPACE,12);


    printf("%s", NAME);

    spaces = (WIDTH -strlen(ADDRESS));

    show_n_chars(SPACE, spaces);
    printf("%s", ADDRESS);

    spaces = (WIDTH -strlen(PLACEHOLDER));

    show_n_chars(SPACE, spaces);

    printf("%s", PLACEHOLDER);

    show_n_chars('*', WIDTH);   

    putchar('\n');

    return 0;
}

void show_n_chars(char ch, int n)
{
    for (int i = 0; i < n; i++)
    {
        putchar(ch);
    }
    putchar('\n');
}
