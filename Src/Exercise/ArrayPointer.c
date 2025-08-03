#include <stdio.h>
#include <string.h>

/**
 * @brief 解释说明 ：https://km.yueya.info/2025/08/03/c%e4%bb%a3%e7%a0%81%e6%8c%87%e9%92%88/
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    //int a[2][3]={0};
    int *a[2][3];
    printf("sizeof(a)  =%d \n",sizeof(a));
    printf("sizeof(*a)  =%d\n",sizeof(*a));
    printf("sizeof(**a)  =%d\n",sizeof(**a));
    printf("sizeof(***a)  =%d\n",sizeof(***a));
    //printf("szieof(a) = %d,szieof(*a) = %d,szieof(**a) = %d,szieof(***a) = %d",szieof(a),szieof(*a),szieof(**a),szieof(***a));
    return 0;
}
