#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*测试读进来的字符是否是介于1与5之间的数字*/

#if 1
int main(int argc, char *argv[]) {
	
	int c = 0;
	printf("Please input a value: ");
	c= getchar();
	if(c != EOF && c>'0' && c< '6')
	{
		printf("The value %c is between one and five",c);
	}
	return 0;
}
#endif
