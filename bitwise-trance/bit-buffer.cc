#include "bit-buffer.h"

BitBuffer::BitBuffer(Buffer *buf){
  this->buf = Buffer::from(buf);
  this->data = buf->data;
  this->len = buf->len;

  this->expand(len);
}

BitBuffer::~BitBuffer(){
  delete[] buf;
  buf = nullptr;
  data = nullptr;
}

void BitBuffer::expand(u8 len){
  u8 lenPrev = this->len;

  if(!len){
    len = 1;
  }else{
    u1 n = 1;
    while(len >>= 1) n++;
    len = 1 << n;
  }

  buf->expand(len);
  this->data = buf->data;
  this->len = len;
}

bit BitBuffer::get(u8 index){
  u8 byteIndex = index >> 3;
  if(byteIndex >= this->len) return 0;

  u1 bitIndex = index & 7;
  return data[byteIndex] & (1 << bitIndex) ? 1 : 0;
}

void BitBuffer::set(u8 index, bit val){
  u8 byteIndex = index >> 3;
  if(byteIndex >= this->len){
    if(!val) return;
    expand(byteIndex + 1);
  }

  u1 bitIndex = index & 7;
  u8 mask = 1 << bitIndex;
  if(val) data[byteIndex] |= mask;
  else data[byteIndex] &= ~mask;
}

void BitBuffer::xor(u8 index){
  u8 byteIndex = index >> 3;
  if(byteIndex >= this->len)
    expand(byteIndex + 1);

  u1 bitIndex = index & 7;
  data[byteIndex] ^= 1 << bitIndex;
}

Buffer *BitBuffer::getBuf()const{
  return buf;
}

u8 BitBuffer::getLen()const{
  return this->len;
}