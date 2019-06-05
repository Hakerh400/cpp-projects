#pragma once

#include "types.h"

class String;

class Base{
public:
  Base();
  virtual ~Base();

  virtual CC className();
  virtual Base* clone(B deep=1);
  virtual B isArray();
  virtual String* toString();
  String* toStr();
};