#include "logger.h"

namespace Logger{
  template<typename T>
  void logVal(T val, bool line){
    std::cout << val;
    if(line) std::cout << std::endl;
  }

  void log(){
    std::cout << std::endl;
  }

  void log(char ch, bool line){
    logVal<char>(ch, line);
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

  void log(Buffer *buf, bool line){
    Buffer *str = Buffer::allocUnsafe(buf->len + 1);
    buf->copy(str);
    str->data[buf->len] = 0;
    logVal<const char*>(str->cdata(), line);
    delete str;
  }

  void log(BitBuffer *bb, bool line){
    u8 len = bb->getLen() << 3;

    for(u8 i = 0; i != len; i++)
      log(bb->get(i) ? '1' : '0', false);

    if(line) log();
  }
}