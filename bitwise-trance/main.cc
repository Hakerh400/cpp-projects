#include "main.h"
#include "logger.h"
#include "fs.h"
#include "buffer.h"
#include "parser.h"
#include "engine.h"

namespace Main{
  int main(u8 argc, const char **argv){
    if(argc != 4)
      return err("Expected 3 argument: source_file input_file output_file");

    const char *srcFile = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];

    Buffer *srcText = FS::readFile(srcFile);
    Buffer *input = FS::readFile(inputFile);

    Buffer *src = Parser::parse(srcText);
    delete srcText;

    Engine *eng = new Engine(src, input);
    delete src;
    delete input;

    Buffer *output = eng->run();
    delete eng;

    if(!output)
      return err("Memory allocation failed");
    
    FS::writeFile(outputFile, output);
    delete output;

    return 0;
  }

  int err(const char *msg){
    Logger::log("ERROR: ", 0);
    Logger::log(msg);

    return 1;
  }
}

int main(u8 argc, const char **argv){
  return Main::main(argc, argv);
}