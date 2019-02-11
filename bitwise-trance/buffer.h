#pragma once

#include "main.h"

class Buffer{
  Buffer(u1 *data, u8 len);

public:
  static Buffer *allocUnsafe(u8 len);
  static Buffer *alloc(u8 len);
  static Buffer *from(u1 *data, u8 len);
  static Buffer *from(Buffer *buf);

  static void filldata(u1 *data, u8 len, u1 byte);
  static void copyData(u1 *src, u1 *dest, u8 len);

  u1 *data;
  u8 len;

  ~Buffer();

  void fill(u1 byte);
  void copy(u1 *dest);
  Buffer *slice(u8 start, u8 end);
  void expand(u8 len);

  u1 get(u8 index);
  void set(u8 index, u1 byte);
};