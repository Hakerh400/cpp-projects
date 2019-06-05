#include "BMPParser.h"
#include "wrapper.h"

void Wrapper::parse(B* dataIn, int size, B** dataOut, int* w, int* h, B** err){
  BMPParser::Parser* parser = new BMPParser::Parser();
  parser->parse(dataIn, size);

  if(parser->getStatus() == BMPParser::Status::ERROR){
    std::string msg = parser->getErrMsg();
    const B* cstr = RC(msg.c_str(), const B*);
    int len = msg.length() + 1;
    B* copy = new B[len];

    for(int i = 0; i != len; i++)
      copy[i] = cstr[i];

    *err = copy;
    return;
  }

  *w = parser->getWidth();
  *h = parser->getHeight();
  *dataOut = RC(parser->getImgd(), B*);
  *err = nullptr;
}