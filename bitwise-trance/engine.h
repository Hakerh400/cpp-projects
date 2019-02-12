#pragma once

#include "main.h"
#include "buffer.h"
#include "io.h"
#include "bit-buffer.h"

class Engine{
  BitBuffer *mem;
  IO *io;
  u8 ip = 0;
  bool err = false;

  u1 readOp();
  u8 readAddr();

public:
  Engine(Buffer *src, Buffer *input);
  ~Engine();

  Buffer *run();

  bool getErr()const;
};