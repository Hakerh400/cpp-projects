#include "log.h"
#include "base.h"

Base::Base(){}

Base::~Base(){}

CC Base::className(){
  return nullptr;
}

Base* Base::clone(B deep){
  return nullptr;
}

B Base::isArray(){
  return 0;
}

String* Base::toString(){
  return nullptr;
}

String* Base::toStr(){
  return this->toString();
}