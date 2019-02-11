#pragma once

#include "main.h"
#include "buffer.h"
#include "io.h"
#include "bit-buffer.h"
#include "parser.h"

class Engine{
  IO *io;
  BitBuffer *mem;
  Parser *parser;

public:
  Engine(u1 *code, u8 codeLen, u1 *input, u8 inputLen);
  ~Engine();
};