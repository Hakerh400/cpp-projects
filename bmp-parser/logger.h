#pragma once

#include "types.h"

class String;
class Base;

template<typename T> T output(T a, int newLine=1);

void outEmptyLine();
char outChar(char a, int newLine=1);
int outInt(int a, int newLine=1);
const char* outStr(const char* a, int newLine=1);
char* outStr(char* a, int newLine=1);