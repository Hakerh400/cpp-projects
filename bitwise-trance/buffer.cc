#include "buffer.h"

Buffer::Buffer(u1 *data, u8 len){
  this->data = data;
  this->len = len;
}

Buffer::~Buffer(){
  delete[] data;
  data = nullptr;
}

Buffer *Buffer::allocUnsafe(u8 len){
  u1 *data = new u1[len];
  return new Buffer(data, len);
}

Buffer *Buffer::alloc(u8 len){
  Buffer *buf = allocUnsafe(len);
  buf->fill(0);
  return buf;
}

Buffer *Buffer::from(u1 *data, u8 len){
  Buffer *buf = allocUnsafe(len);
  copyData(data, buf->data, len);
  return buf;
}

Buffer *Buffer::from(Buffer *buf){
  return from(buf->data, buf->len);
}

void Buffer::filldata(u1 *data, u8 len, u1 byte){
  for(u8 i = 0; i != len; i++)
    data[i] = byte;
}

void Buffer::copyData(u1 *src, u1 *dest, u8 len){
  while(len--) *dest++ = *src++;
}

void Buffer::fill(u1 byte){
  filldata(data, len, byte);
}

void Buffer::copy(u1 *dest){
  copyData(data, dest, len);
}

Buffer *Buffer::slice(u8 start, u8 end){
  return new Buffer(data + start, end - start);
}

void Buffer::expand(u8 len){
  u1 *data = new u1[len];
  copyData(this->data, data, this->len);
  filldata(data + this->len, len - this->len, 0);
  delete[] this->data;
  this->data = data;
  this->len = len;
}

u1 Buffer::get(u8 index){
  return this->data[index];
}

void Buffer::set(u8 index, u1 byte){
  this->data[index] = byte;
}