#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*���Զ��������ַ��Ƿ��ǽ���1��5֮�������*/

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
