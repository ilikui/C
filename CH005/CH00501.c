#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#if 0
int main(int argc, char *argv[]) {
	
	int a,b;
	int * ipointer1,* ipointer2; /*��������ָ�����*/
	scanf("%d,%d",&a,&b);
	ipointer1 = &a;
	ipointer2 = &b;/*����ַ����ָ�����*/
	printf("The number is %d,%d\n",*ipointer1,*ipointer2);
	return 0;
}
#endif
