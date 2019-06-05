#pragma once

#include "types.h"

class String;

class FileSystem{
public:
  static B* read(CC file, int* len);
  static void write(CC file, B* buf, int len);
};