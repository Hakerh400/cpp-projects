#include "log.h"
#include "file-system.h"

#include <fstream>

B* FileSystem::read(CC file, int* len){
  std::ifstream handle(file, std::ios::binary | std::ios::ate);
  std::streamsize size = handle.tellg();
  handle.seekg(0, std::ios::beg);

  B* data = new B[size + 1];
  handle.read(RC(data, char*), size);
  data[size] = 0;

  *len = size;
  return data;
}

void FileSystem::write(CC file, B* buf, int len){
  std::ofstream handle(file, std::ios::binary | std::ios::ate);
  handle.write(RC(buf, char*), len);
}