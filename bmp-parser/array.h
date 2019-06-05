#pragma once

#include "types.h"
#include "base.h"

class String;

class Array: public Base{
private:
  int size;
  int length;

public:
  Base** d;

  Array();
  ~Array();

  int len();
  void len(int len);

  Array* unshift(Base* val);
  Array* unshift(const char* str);
  Array* push(Base* val);
  Array* push(const char* str);
  Base* shift();
  Base* pop();

  Array* expand();
  Array* unref();

  CC className();
  virtual Base* clone(B deep=1);
  virtual B isArray();
  virtual String* toString();
};