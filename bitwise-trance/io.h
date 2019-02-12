#pragma once

#include "main.h"
#include "buffer.h"
#include "math.h"

class IO{
  Buffer *input;
  Buffer *output;
  bool pad;

  u8 inputIndex;
  u8 outputIndex = 0;
  u8 byte = 0;

  void addByte();

public:
  IO(Buffer *input=nullptr, bool pad=false);
  ~IO();

  bit read();
  void write(bit val);
  bool hasMore();
  Buffer *getOutput();
};