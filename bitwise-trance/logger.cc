#include "logger.h"

namespace Logger{
  template<typename T>
  void logVal(T val, bool line){
    std::cout << val;
    if(line) std::cout << std::endl;
  }

  void log(u1 ch, bool line){
    logVal<u1>(ch, line);
  }

  void log(u8 num, bool line){
    logVal<u8>(num, line);
  }

  void log(const char *str, bool line){
    logVal<const char*>(str, line);
  }
}