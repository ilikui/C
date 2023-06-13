#include <stdio.h>

#define PI 3.14159
int main(int argc, char const *argv[])
{
    float area,circum,radius;
    printf("Enter radius of the circle\n");
    scanf("%f",&radius);
    area=PI*radius*radius;
    circum=2*PI*radius;
    printf("Area of the circle is %f\n",area);
    printf("Circumference of the circle is %f\n",circum);
    printf("Area of the circle is %f\n",area);
    return 0;
}
