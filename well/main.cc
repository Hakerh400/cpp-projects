#include <iostream>
#include <windows.h>

#pragma comment(lib, "user32.lib") 

#define log(a) std::cout << a << std::endl;

struct Key{
  int code;
  bool ext;

  Key(int code, bool ext=false){
    this->code = code;
    this->ext = ext;
  }

  DWORD getFlag(){
    return KEYEVENTF_SCANCODE |
      (ext ? KEYEVENTF_EXTENDEDKEY : 0);
  }
};

Key Left  (0x4B, true);
Key Right (0x4D, true);
Key Down  (0x50, true);
Key Up    (0x48);
Key Space (0x39);
Key KeyS  (0x1F);

struct Jar{
  Jar *left;
  Jar *right;

  Jar(Jar *left, Jar *right){
    this->left = left;
    this->right = right;
  }
};

Jar *Empty = nullptr;

Jar *Pair(Jar *left, Jar *right){
  return new Jar(left, right);
}

bool isEmpty(Jar *jar){
  return jar == nullptr;
}

bool isPair(Jar *jar){
  return !isEmpty(jar);
}

int depth = 5;
int exitCooldown = 2000;

Jar *r2(int n, Jar *x);
Jar *r1(int n);

Jar *r2(int n, Jar *x){
  if(n == 1)
    return Pair(Empty, x);

  return r2(n - 1, Pair(r1(n), x));
}

Jar *r1(int n){
  return r2(n - 1, Empty);
}

void release(Key key){
  INPUT ip;

  ip.type = INPUT_KEYBOARD;
  ip.ki.time = 0;
  ip.ki.wVk = 0;
  ip.ki.dwExtraInfo = 0;

  ip.ki.wScan = key.code;

  DWORD flag = key.getFlag();

  ip.ki.dwFlags = flag | KEYEVENTF_KEYUP;
  SendInput(1, &ip, sizeof(INPUT));
}

void press(Key key, int time=100){
  INPUT ip;

  ip.type = INPUT_KEYBOARD;
  ip.ki.time = 0;
  ip.ki.wVk = 0;
  ip.ki.dwExtraInfo = 0;

  ip.ki.wScan = key.code;

  DWORD flag = key.getFlag();

  ip.ki.dwFlags = flag;
  SendInput(1, &ip, sizeof(INPUT));

  if(time != -1){
    Sleep(time);
    release(key);
  }
}

void hold(Key key){
  press(key, -1);
}

void dropDown(){
  hold(KeyS);
  press(Space);
  release(KeyS);
}

void gotoFirstJarSpot(){
  press(Right, 650);
}

void gotoSecondJarSpot(){
  press(Right, 850);
}

void gotoJarSpot(int i){
  if(i == 0) gotoFirstJarSpot();
  else gotoSecondJarSpot();
  Sleep(500);
}

void makeJar(int i){
  gotoJarSpot(i);
  press(Space);
  Sleep(2000);
}

void enterChest(){
  press(Up);
  press(Left, 200);
  Sleep(1700);
}

int main(){
  // Initial time
  Sleep(1000);

  // Grab the chest and put in into the well
  press(Left, 350);
  press(Space);
  press(Right, 600);
  press(Up);
  press(Right, 450);
  Sleep(500);
  dropDown();
  press(Right, 200);
  Sleep(250);

  // Compute the main jar
  Jar *mainJar = r2(depth, Empty);

  enterChest();
  makeJar(0);

  enterChest();
  makeJar(1);

  return 0;
}