#include "log.h"
#include "base.h"
#include "string.h"
#include "array.h"
#include "integer.h"

Integer::Integer(int val){
  this->val = val;
}

Integer::Integer(Integer* val){
  this->val = val->val;
}

Integer::~Integer(){}

CC Integer::className(){
  return "Integer";
}

Base* Integer::clone(B deep){
  return new Integer(this);
}

String* Integer::toString(){
  if(val == 0) return new String("0");

  String* s = new String("");
  int v = val;

  v = ABS(v);

  while(v != 0){
    s->add('0' + v % 10);
    v /= 10;
  }

  if(val < 0) s->add('-');

  return s->reverse();
}