#include <stdio.h>

/**
 * @brief 数据和C
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const *argv[])
{
    float weight;
    float value;

    printf("Are u worth your weight in platinum?\n");
    printf("Let's check it out\n");
    printf("Please enter your weight in pounds: ");

    scanf("%f", &weight);
    value = 1700.0 * weight * 14.5833;
    printf("Your weight in platinum is worth $%.2f .\n", value);

    printf("Your are easilly worth that ! if platinum prices drop,\n");
    printf("eat more to maintain your value.\n");
    return 0;
}
