#include <stdio.h>

int main(void)
{
	int i,j;
	i = 1;
	j = 3;
	while(i<=5)
	{
		j = j*i;
		i = i +2;
	}

	printf("%d\n",j);

	return 0;
}