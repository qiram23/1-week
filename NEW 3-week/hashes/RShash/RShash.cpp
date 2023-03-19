#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <map>

using namespace std;

unsigned int RShashh(const char* str, unsigned int length){
    unsigned int b    = 378551;
    unsigned int a    = 63689;
    unsigned int hashh = 0;
    unsigned int i    = 0;

    for (i = 0; i < length; ++str, ++i)
    {
       hashh = hashh * a + (*str);
       a    = a * b;
    }
    return hashh;
}


int main()
{
  ofstream fout;
  fout.open("RSgraph1.txt");
  map<long long int, int> count;
  for (int y = 10; y <= 4000000; y *= 5)
  {
    const int cycles = y;
    vector<long long int> hah;
    int len;
    const char* s;
    string h;
    for (int i = 0; i < cycles; i++)
    {
      h = "";
      len = 15;
      for (int n = 0; n < len; ++n){h += (char)rand()%(255-0+1)+255;}
      s = h.c_str();
      hah.push_back(RShashh(s, len));
    }
    for (int i = 0; i < cycles; i++){count[hah[i]]++;}
    double coun = 0;
    for (auto i : count)
    {
      if (i.second > 1){coun += i.second;}
    }

    fout << y << "  " << coun << endl;
  }
  fout.close();
  fout.open("RSgraph2.txt");
  for (auto i : count) {fout << i.first << "  " << i.second << endl;}
  fout.close();

  ////////////////////////////////////////////////////////////////////////////////////////////



  return 0;
}
