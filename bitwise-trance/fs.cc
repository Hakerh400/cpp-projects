#include <fstream>
#include "fs.h"

namespace FS{
  Buffer *readFile(const char *path){
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    u8 len = file.tellg();
    file.seekg(0, std::ios::beg);

    Buffer *buf = Buffer::allocUnsafe(len);
    file.read(buf->cdata(), len);
    file.close();

    return buf;
  }

  void writeFile(const char *path, Buffer *buf){
    std::ofstream file(path, std::ios::binary);
    file.write(buf->cdata(), buf->len);
    file.close();
  }
}