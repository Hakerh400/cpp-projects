#include "main.h"
#include "logger.h"
#include "buffer.h"
#include "io.h"
#include "engine.h"
#include "bit-buffer.h"

namespace Main{
  int main(){
    IO *io = new IO();

    for(u8 i = 0; i != 3; i++){
      io->write(1); io->write(1); io->write(1); io->write(0);
      io->write(1); io->write(1); io->write(0); io->write(0);
    }

    Buffer *buf = io->getOutput();

    for(u8 i = 0; i != buf->len; i++)
      Logger::log(buf->get(i), 0);

    Logger::log("");

    delete buf;
    delete io;

    return 0;
  }
}

int main(){
  return Main::main();
}