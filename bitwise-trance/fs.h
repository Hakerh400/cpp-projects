#include "main.h"
#include "buffer.h"

namespace FS{
  Buffer *readFile(const char *path);
  void writeFile(const char *path, Buffer *buf);
};