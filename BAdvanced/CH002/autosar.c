#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pint(t)   printf("the func is:%d\n",t);

void print1(int);
void print2(int);
void print3(int);
void print4(int);

typedef void(*print_fun)(int);

int main(void)
{
    int i;
	print_fun pointer_funs[4]={print1,print2,print3,print4};

	for(i=0;i<4;i++)
	{
		pointer_funs[3-i](i);
	}
	return 0;
}

void print1(int a){
	printf("hello,input %d  :",a);
	pint(1);	
}

void print2(int a){
	printf("hello,input %d  :",a);
	pint(2);	
}

void print3(int a){
	printf("hello,input %d  :",a);
	pint(3);	
}

void print4(int a){
	printf("hello,input %d  :",a);
	pint(4);	
}
