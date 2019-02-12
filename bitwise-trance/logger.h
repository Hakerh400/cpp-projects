#pragma once

#include "main.h"
#include "buffer.h"
#include "bit-buffer.h"

namespace Logger{
  template<typename T>
  void logVal(T val, bool line=true);

  void log();
  void log(char ch, bool line=true);
  void log(u1 ch, bool line=true);
  void log(u8 num, bool line=true);
  void log(const char *str, bool line=true);
  void log(Buffer *buf, bool line=true);
  void log(BitBuffer *bb, bool line=true);
}