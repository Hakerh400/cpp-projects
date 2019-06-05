#include "logger.h"
#include "log.h"

void log(){
  outEmptyLine();
}

char log(char a, int newLine){
  return outChar(a, newLine);
}

int log(int a, int newLine){
  return outInt(a, newLine);
}

const char* log(const char* a, int newLine){
  return outStr(a, newLine);
}

char* log(char* a, int newLine){
  return outStr(a, newLine);
}