#pragma once

#define N nullptr

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define SGN(a) ((a) > 0 ? 1 : (a < 0) ? -1 : 0)
#define BOUND(a, b, c) MIN(MAX(a, b), c)

#define CAST(a, b, c) a##_cast<b>(c)
#define SC(a, b) CAST(static, b, a)
#define RC(a, b) CAST(reinterpret, b, a)
#define CL(a, b) RC((a)->clone(), b*)

#define M(a, b) b a(); void a(b);

typedef unsigned char B;
typedef signed char S8;
typedef unsigned short W;
typedef short S;
typedef unsigned int U;
typedef const char* CC;