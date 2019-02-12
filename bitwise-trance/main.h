#pragma once

#include <iostream>

typedef bool bit;

typedef int8_t i1;
typedef int16_t i2;
typedef int32_t i4;
typedef int64_t i8;

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;

namespace Main{
  int main(u8 argc, const char **argv);
  int err(const char *msg);
}

int main(u8 argc, const char **argv);