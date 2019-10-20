#include "log.h"
#include "base.h"
#include "integer.h"
#include "string.h"
#include "array.h"

Array::Array(){
  length = 0;
  size = 1;
  d = new Base*[size];
}

Array::~Array(){
  for(int i = 0; i != size; i++){
    if(i < length) delete d[i];
    d[i] = nullptr;
  }

  delete[] d;
  d = nullptr;
}

int Array::len(){
  return length;
}

void Array::len(int len){
  for(int i = length; i != len; i++)
    delete d[i];

  length = len;
}

Array* Array::unshift(Base* val){
  if(length == size) expand();

  for(int i = length; i != 0; i--)
    d[i] = d[i - 1];

  d[0] = val;
  length++;

  return this;
}

Array* Array::unshift(CC str){
  return unshift(new String(str));
}

Array* Array::push(Base* val){
  if(length == size) expand();
  d[length++] = val;
  return this;
}

Array* Array::push(CC str){
  return push(new String(str));
}

Base* Array::shift(){
  Base* val = d[0];
  length--;

  for(int i = 0; i != length; i++)
    d[i] = d[i + 1];

  return this;
}

Base* Array::pop(){
  return d[--length];
}

Array* Array::expand(){
  int len1 = size;
  int len2 = len1 << 1;

  Base** d1 = new Base*[len2];

  for(int i = 0; i != len1; i++){
    d1[i] = d[i];
    d[i] = nullptr;
  }

  delete[] d;
  d = d1;

  size = len2;
  return this;
}

Array* Array::unref(){
  for(int i = 0; i != size; i++)
    d[i] = nullptr;

  return this;
}

CC Array::className(){
  return "Array";
}

Base* Array::clone(B deep){
  Array* a = new Array();

  for(int i = 0; i != length; i++){
    a->push(d[i] && deep ? d[i]->clone() : d[i]);
  }

  return a;
}

B Array::isArray(){
  return 1;
}

String* Array::toString(){
  String* s = new String("[");

  for(int i = 0; i != length; i++){
    if(i != 0) s->add(", ");

    String *temp = d[i]->toString();
    s->add(temp);
    delete temp;
  }

  return s->add("]");
}