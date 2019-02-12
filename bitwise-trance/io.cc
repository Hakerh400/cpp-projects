#include "io.h"

IO::IO(Buffer *input, bool pad){
  this->input = input ? Buffer::from(input) : Buffer::alloc(0);
  this->output = Buffer::alloc(1);
  this->pad = pad;
  this->inputIndex = pad ? 0 : 1;
}

IO::~IO(){
  delete input;
  delete output;
  input = nullptr;
  output = nullptr;
}

void IO::addByte(){
  u8 len = outputIndex - 1 >> 3;

  if(len == output->len)
    output->expand(len << 1);

  output->data[len] = byte;
  byte = 0;
}

bit IO::read(){
  u8 i = inputIndex;

  if((i >> 4) >= input->len) return 0;
  inputIndex += pad ? 1 : 2;

  if(!(i & 1)) return 1;
  return input->data[i >> 4] & (1 << ((i >> 1) & 7)) ? 1 : 0;
}

void IO::write(bit val){
  byte |= val << (outputIndex++ & 7);
  if(!(outputIndex & 7)) addByte();
}

bool IO::hasMore(){
  return (inputIndex >> 4) < input->len;
}

Buffer *IO::getOutput(){
  if(outputIndex & 7) addByte();

  u8 len = Math::ceilShift(outputIndex, 3);
  Buffer *bufPart = output->slice(0, len);
  Buffer *buf = Buffer::from(bufPart);
  
  bufPart->removeData();
  delete bufPart;
  
  return buf;
}