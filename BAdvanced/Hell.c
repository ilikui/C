#include <stdio.h>
#include <math.h>

typedef float real32_T;
typedef double real_T;

typedef unsigned char uint8 ;

typedef uint8 U2;
typedef int int32_T;

typedef unsigned char uint8_T;


typedef signed char int8_T;

real32_T rt_roundf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}


int main(int argc, char const *argv[])
 {

   
       real32_T Lookuptable_iarout2_tmp;
       real_T ChrgnUReqLocal;
      
        U2 Switch;
        ChrgnUReqLocal = 10.58741;
        Lookuptable_iarout2_tmp = (real32_T)fmod(rt_roundf(((real32_T)ChrgnUReqLocal
        - 10.6F) / 0.025F), 256.0);

    

       
        Switch = (U2)(Lookuptable_iarout2_tmp < 0.0F ? (int32_T)(uint8_T)-(int8_T)
        (uint8_T)-Lookuptable_iarout2_tmp : (int32_T)(uint8_T)
        Lookuptable_iarout2_tmp);

       

        printf("%d",Switch);

    return 0;
}
