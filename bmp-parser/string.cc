#include "log.h"
#include "base.h"
#include "integer.h"
#include "array.h"
#include "string.h"

String::String(){
  str = new char[1];
  str[0] = 0;
}

String::String(char c){
  str = new char[2];
  str[0] = c;
  str[1] = 0;
}

String::String(CC str){
  this->str = strClone(str);
}

String::String(String* str){
  this->str = strClone(str->str);
}

String::~String(){
  delete this->str;
  this->str = N;
}

int String::strLen(CC str){
  int i = 0;
  while(str[i++] != 0);
  return i - 1;
}

int String::strLen(String* str){
  return strLen(str->str);
}

char* String::strClone(CC str){
  char* s = new char[strLen(str) + 1];
  String::strCopy(str, s);
  return s;
}

char* String::strCopy(CC s1, char *s2){
  int i = 0;

  while(s1[i] != 0){
    s2[i] = s1[i];
    i++;
  }

  s2[i] = 0;
  return s2;
}

char* String::strConcat(CC s1, CC s2){
  int len1 = strLen(s1);
  int len2 = strLen(s2);

  char* s = new char[len1 + len2 + 1];
  strCopy(s1, s);
  strCopy(s2, s + len1);

  return s;
}

B String::strEq(CC s1, CC s2){
  int len1 = strLen(s1);
  int len2 = strLen(s2);
  if(len1 != len2) return 0;

  for(int i = 0; i != len2; i++)
    if(s1[i] != s2[i]) return 0;

  return 1;
}

B String::strStartsWith(CC s1, CC s2){
  int len1 = strLen(s1);
  int len2 = strLen(s2);
  if(len2 > len1) return 0;

  for(int i = 0; i != len2; i++)
    if(s1[i] != s2[i]) return 0;

  return 1;
}

B String::strEndsWith(CC s1, CC s2){
  int len1 = strLen(s1);
  int len2 = strLen(s2);
  if(len2 > len1) return 0;

  for(int i = 0; i != len2; i++)
    if(s1[i + len1 - len2] != s2[i]) return 0;

  return 1;
}

int String::len(){
  return strLen(this);
}

char String::fst(){
  return str[0];
}

String* String::set(CC str){
  delete this->str;
  this->str = strClone(str);
  return this;
}

String* String::set(String* str){
  return set(str->str);
}

String* String::add(char c){
  String* s = new String(c);
  this->add(s);
  delete s;
  return this;
}

String* String::add(CC str){
  char* s = strConcat(this->str, str);
  delete this->str;
  this->str = s;
  return this;
}

String* String::add(String* str){
  return add(str->str);
}

String* String::reverse(){
  String* s = CL(this, String);
  set("");

  for(int i = s->len() - 1; i != -1; i--)
    add(s->str[i]);

  delete s;
  return this;
}

String* String::repeat(int num){
  String* s = CL(this, String);
  set("");

  while(num--) add(s);
  delete s;

  return this;
}

String* String::padStart(int num, char ch){
  int dif = num - len();

  if(dif > 0){
    String* s = (new String(ch))->repeat(dif);
    String* temp = CL(s, String)->add(this);
    set(temp);
    delete temp;
    delete s;
  }

  return this;
}

String* String::padEnd(int num, char ch){
  int dif = num - len();

  if(dif > 0){
    String* s = (new String(ch))->repeat(dif);
    add(s);
    delete s;
  }

  return this;
}

String* String::slice(int start, int end){
  int len = this->len();
  start = BOUND(start, 0, len);
  end = end == -1 ? len : BOUND(end, 0, len);

  String* s = new String();

  for(int i = start; i < end; i++)
    s->add(str[i]);

  set(s);
  delete s;

  return this;
}

B String::eq(CC str){
  return strEq(this->str, str);
}

B String::startsWith(CC str){
  return strStartsWith(this->str, str);
}

B String::endsWith(CC str){
  return strEndsWith(this->str, str);
}

B String::isInt(){
  int len = this->len();
  int hex = 0;

  if(len == 0) return 0;
  if(len == 1) return str[0] >= '0' && str[0] <= '9';

  for(int i = 0; i != len; i++){
    char c = str[i];
    if(c >= '0' && c <= '9' || i == 0 && (c == '+' || c == '-')) continue;
    if(hex && (c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F')) continue;
    if(i != len - 1 && (c == 'x' || c == 'X')){
      hex = 1;
      if(i == 1 && str[0] == '0') continue;
      if(i == 2 && (str[0] == '+' || str[0] == '-') && str[1] == '0') continue;
    }
    return 0;
  }

  return 1;
}

int String::intVal(){
  int len = this->len();
  int num = 0;
  int sign = 1;
  int hex = 0;
  int i = 0;

  if(str[0] == '+' || str[0] == '-'){
    if(str[0] == '-') sign = -1;
    i++;
  }

  if(str[i + 1] == 'x' || str[i + 1] == 'X'){
    hex = 1;
    i += 2;
  }

  while(i != len){
    char c = str[i++];

    int n = c >= '0' && c <= '9' ? c - '0' :
      (c >= 'a' && c <= 'f' ? c - 'a' : c - 'A') + 10;

    num = num * (hex ? 16 : 10) + n;
  }

  return num * sign;
}

CC String::className(){
  return "String";
}

Base* String::clone(B deep){
  return new String(this);
}

String* String::toString(){
  return CL(this, String);
}