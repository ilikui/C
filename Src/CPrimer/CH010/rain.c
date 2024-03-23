#include <stdio.h>

/**
 * @brief 数组的使用规则与规范  一维数组 .. 多维数组
 *
 * @param argc
 * @param argv
 * @return int
 */
#define MONTHES 12
#define YEARS 5

int main(int argc, char const *argv[])
{

    int year, month;

    float subtot, total;

    const float rain[YEARS][MONTHES]={

        {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 1.10, 1.11, 1.12},
        {2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 2.10, 2.11, 2.12},
        {3.1, 3.2, 1.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 3.10, 3.11, 3.12},
        {4.1, 4.2, 1.3, 4.4, 4.5, 4.6, 4.7, 4.8, 4.9, 4.10, 4.11, 4.12},
        {5.1, 5.2, 1.3, 5.4, 5.5, 5.6, 5.7, 5.8, 5.9, 5.10, 5.11, 5.12}};

    for (year = 0, total = 0; year < YEARS; year++)
    {
        for (month = 0, subtot = 0; month < MONTHES; month++)
        {
            subtot += rain[year][month];
            printf("%5d %15.1f\n", 2019 + year, subtot);
        }

        total += subtot; /*5年的总降水量*/
    }

    printf("%f\n", total);

    return 0;
}
