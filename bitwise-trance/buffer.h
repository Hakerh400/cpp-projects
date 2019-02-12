#pragma once

#include "main.h"

class Buffer{
  Buffer(u1 *data, u8 len);

public:
  static Buffer *allocUnsafe(u8 len);
  static Buffer *alloc(u8 len);
  static Buffer *from(u1 *data, u8 len);
  static Buffer *from(Buffer *buf);
  static Buffer *concat(Buffer *buf1, Buffer *buf2);

  static void filldata(u1 *data, u8 len, u1 byte);
  static void copyData(u1 *src, u1 *dest, u8 len);

  u1 *data;
  u8 len;

  ~Buffer();

  void fill(u1 byte);
  void copy(u1 *dest, u8 destStart, u8 srcStart, u8 srcEnd);
  void copy(u1 *dest, u8 destStart=0, u8 srcStart=0);
  void copy(Buffer *dest, u8 destStart, u8 srcStart, u8 srcEnd);
  void copy(Buffer *dest, u8 destStart=0, u8 srcStart=0);
  Buffer *slice(u8 start, u8 end);
  bool expand(u8 len);

  void removeData();
  void replaceData(u1 *data);

  u1 get(u8 index);
  void set(u8 index, u1 byte);

  char *cdata();
};