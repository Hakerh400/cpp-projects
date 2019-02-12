#include "engine.h"

#define MAX_ADDR_SIZE 62

Engine::Engine(Buffer *src, Buffer *input){
  mem = new BitBuffer(src);
  io = new IO(input, 1);
}

Engine::~Engine(){
  delete io;
  delete mem;
  io = nullptr;
  mem = nullptr;
}

u1 Engine::readOp(){
  u1 op = (mem->get(ip) ? 2 : 0) | (mem->get(ip + 1) ? 1 : 0);
  ip += 2;
  return op;
}

u8 Engine::readAddr(){
  u8 num = 0;
  u8 mask = 1;
  u1 len = 0;

  while(mem->get(ip++)){
    if(++len == MAX_ADDR_SIZE) err = true;
    if(mem->get(ip++)) num |= mask;
    mask <<= 1;
  }

  return (num | mask) - 1;
}

Buffer *Engine::run(){
  bool running = true;
  bool even = true;

  while(running){
    u8 addr0 = readAddr();
    u1 op1 = readOp();
    u8 addr1 = readAddr();
    u1 op2 = readOp();
    u8 addr2 = readAddr();

    if(err) return nullptr;

    bit b = mem->get(addr0);
    u8 addr = b ? addr2 : addr1;
    u1 op = b ? op2 : op1;

    switch(op){
      case 0b00: // jmp
        ip = addr;
        break;

      case 0b01: // xor
        mem->xor(addr);
        break;

      case 0b10: // in
        b = io->read();
        mem->set(addr, b);
        break;

      case 0b11: // out
        b = mem->get(addr);
        if(even){
          if(!b) running = false;
          even = false;
        }else{
          io->write(b);
          even = true;
        }
        break;
    }

    if(mem->getErr()){
      err = true;
      return nullptr;
    }
  }

  return io->getOutput();
}

bool Engine::getErr()const{
  return err;
}