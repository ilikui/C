#include <stdio.h>
#include <stdlib.h>

#define MY_WEIGHT 60

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#if 0
int main(int argc, char *argv[]) {
	
	int your_weight = 0;
	
	printf("Please enter your weight:");
	scanf("%d",&your_weight);
	if(your_weight > MY_WEIGHT)
		printf("You are heavier than me.\n");
	if(your_weight < MY_WEIGHT)
		printf("I am heavier than you.\n");
	if(your_weight == MY_WEIGHT)
		printf("We sre exactly the same weight.\n");

	
	return 0;
}
#endif
