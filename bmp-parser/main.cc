#include "log.h"
#include "base.h"
#include "integer.h"
#include "string.h"
#include "array.h"
#include "file-system.h"
#include "wrapper.h"

int main(int* argc, char** argv){
  int size;
  B* bmp = FileSystem::read("GIT" "_EXCLUDE/img.bmp", &size);

  int w, h;
  B* data;
  B* err;
  Wrapper::parse(bmp, size, &data, &w, &h, &err);

  if(err){
    log(RC(err, char*));
    return 1;
  }

  FileSystem::write("GIT" "_EXCLUDE/img.hex", data, w * h << 2);

  String* str = new String("@echo off\ncls\n\ncall ffmpeg -y -f rawvideo -pix_fmt rgba -s ");
  str->add((new Integer(w))->toString());
  str->add("x");
  str->add((new Integer(h))->toString());
  str->add(" -i \"img.hex\" \"C:/wamp/www/projects/image/1.png\"");
  FileSystem::write("GIT" "_EXCLUDE/f.bat", RC(str->str, B*), str->len());

  return 0;
}