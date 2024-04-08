#include <stdio.h>

int main(int argc, char const *argv[])
{
    int money;
    printf("Ask ");
    scanf("%d",&money);
    if(money >100)
    {
        printf("More than");
    }else
    {
        printf("End");
    }
    return 0;
}
