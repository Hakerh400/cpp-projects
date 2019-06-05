#include "logger.h"

#include <iostream>

template<typename T> T output(T a, int newLine){
  std::cout << a;
  if(newLine) std::cout << "\n";
  return a;
}

void outEmptyLine(){
  output<const char*>("");
}

char outChar(char a, int newLine){
  return output<char>(a, newLine);
}

int outInt(int a, int newLine){
  return output<int>(a, newLine);
}

const char* outStr(const char* a, int newLine){
  return output<const char*>(a, newLine);
}

char* outStr(char* a, int newLine){
  return output<char*>(a, newLine);
}