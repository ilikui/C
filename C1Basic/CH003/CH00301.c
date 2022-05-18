#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#if 0
int main(int argc, char *argv[]) {
	
	int number = 0;
	int * pointer = NULL;
	number = 10;
	printf("\n number's address :%p",&number);
	printf("\n number's value :%d\n\n",number);
	
	pointer = &number;
    printf("\n pointer's address :%p",&pointer);
	printf("\n pointer's size :%d bytes",sizeof(pointer));
	return 0;
}
#endif
