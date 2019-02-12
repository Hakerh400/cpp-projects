#include "parser.h"

namespace Parser{
  Buffer *parse(Buffer *srcText){
    u1 *d = srcText->data;
    u8 len = srcText->len;

    IO *io = new IO();

    for(u8 i = 0; i != len; i++){
      if(d[i] == '0') io->write(0);
      else if(d[i] == '1') io->write(1);
    }

    Buffer *src = io->getOutput();
    delete io;

    return src;
  }
}