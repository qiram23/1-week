#include <iostream>
#include <vector>
#include <string>

using namespace std;

unsigned int RShashh(float f) {
  unsigned int b = 378551;
  unsigned int a = 63689;
  unsigned int hh = 0;
  unsigned int i = 0;

  const char* str = to_string(f).c_str();
  unsigned int length = to_string(f).length();

  for (i = 0; i < length; ++str, ++i)
  {
    hh = hh * a + (*str);
    a = a * b;
  }
  return hh;
}

int main() {

  float fir = 1.234987;
  float sec = -12.6456f;

  cout << RShashh(fir) << endl;
  cout << RShashh(sec) << endl;

    return 0;
}
