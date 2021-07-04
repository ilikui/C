#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#if 0
int main(int argc, char *argv[]) {
	
	int counter;
	int grade;
	int total;
	int average;
	/*init phase*/
	
	total = 0;
	counter = 1;
	while(counter <= 10)
	{
		printf("Enter grade: ");
		scanf("%d",&grade);
		total =  total + grade;
		counter++;
	}
	average = total / 10;
	printf("Class average is %d\n",average); 
	return 0;
}
#endif
