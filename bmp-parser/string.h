#pragma once

#include "types.h"
#include "base.h"

class String: public Base{
public:
  char* str;

  String();
  String(char c);
  String(CC str);
  String(String* str);
  ~String();

  static int strLen(CC str);
  static int strLen(String* str);
  static char* strClone(CC str);
  static char* strCopy(CC s1, char* s2);
  static char* strConcat(CC s1, CC s2);
  B strEq(CC s1, CC s2);
  B strStartsWith(CC s1, CC s2);
  B strEndsWith(CC s1, CC s2);

  int len();
  char fst();

  String* set(CC str);
  String* set(String* str);

  String* add(char c);
  String* add(CC str);
  String* add(String* str);

  String* reverse();
  String* repeat(int num);
  String* padStart(int num, char ch=' ');
  String* padEnd(int num, char ch=' ');
  String* slice(int start, int end=-1);

  B eq(CC str);
  B startsWith(CC str);
  B endsWith(CC str);

  B isInt();
  int intVal();

  virtual CC className();
  virtual Base* clone(B deep=1);
  virtual String* toString();
};