#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#if 0
int main(int argc, char *argv[]) {
	
	double amount;
	double principal = 1000.0;
	double rate = 0.05;
	int year;
	printf("%4s%21s\n","Year","Amount on deposit");
	
	for(year = 1;year<=10;year++)
	{
		amount = principal * pow(1.0 + rate,year);
		
		printf("%4d%21.2f\n",year,amount);
	}
	return 0;
}
#endif
