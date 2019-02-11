#include "math.h"

namespace Math{
  u8 ceil(u8 a, u8 b){
    u8 c = a / b;
    if(a % b) c++;
    return c;
  }

  u8 ceilShift(u8 a, u1 b){
    u8 c = a >> b;
    if(a & (1 << b) - 1) c++;
    return c;
  }
}