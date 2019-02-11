#pragma once

#include "main.h"
#include "buffer.h"

class BitBuffer{
  Buffer *buf;
  u1 *data;
  u8 len;

  void expand(u8 len);

public:
  BitBuffer(Buffer *buf);
  ~BitBuffer();

  bit get(u8 index);
  void set(u8 index, bit val);
  void xor(u8 index);

  Buffer *getBuf()const;
  u8 getLen()const;
};