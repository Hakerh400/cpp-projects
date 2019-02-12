#include "buffer.h"

Buffer::Buffer(u1 *data, u8 len){
  this->data = data;
  this->len = len;
}

Buffer::~Buffer(){
  if(data){
    delete[] data;
    data = nullptr;
  }
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

Buffer *Buffer::concat(Buffer *buf1, Buffer *buf2){
  Buffer *buf = Buffer::allocUnsafe(buf1->len + buf2->len);
  buf1->copy(buf);
  buf2->copy(buf, buf1->len);
  return buf;
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

void Buffer::copy(u1 *dest, u8 destStart, u8 srcStart, u8 srcEnd){
  copyData(data + srcStart, dest + destStart, srcEnd - srcStart);
}

void Buffer::copy(u1 *dest, u8 destStart, u8 srcStart){
  copy(data, destStart, srcStart, len);
}

void Buffer::copy(Buffer *dest, u8 destStart, u8 srcStart, u8 srcEnd){
  copy(dest->data, destStart, srcStart, srcEnd);
}

void Buffer::copy(Buffer *dest, u8 destStart, u8 srcStart){
  copy(dest->data, destStart, srcStart, len);
}

Buffer *Buffer::slice(u8 start, u8 end){
  return new Buffer(data + start, end - start);
}

bool Buffer::expand(u8 len){
  u1 *data = new (std::nothrow) u1[len];
  if(!data) return false;

  copyData(this->data, data, this->len);
  filldata(data + this->len, len - this->len, 0);
  
  delete[] this->data;
  this->data = data;
  this->len = len;

  return true;
}

void Buffer::removeData(){
  data = nullptr;
}

void Buffer::replaceData(u1 *data){
  delete[] this->data;
  this->data = data;
}

u1 Buffer::get(u8 index){
  return this->data[index];
}

void Buffer::set(u8 index, u1 byte){
  this->data[index] = byte;
}

char *Buffer::cdata(){
  return reinterpret_cast<char*>(data);
}