#pragma once

#include "types.h"
#include "base.h"

class String;

class Integer : public Base{
public:
  int val;

  Integer(int val=0);
  Integer(Integer* val);
  ~Integer();

  virtual const char* className();
  virtual Base* clone(B deep=1);
  virtual String* toString();
};