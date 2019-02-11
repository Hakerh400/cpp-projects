#pragma once

#include "main.h"

namespace Logger{
  template<typename T>
  void logVal(T val, bool line=true);

  void log(u1 ch, bool line=true);
  void log(u8 num, bool line=true);
  void log(const char *str, bool line=true);
}