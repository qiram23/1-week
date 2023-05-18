#include <functional>
#include <iostream>

using namespace std;

void Print(){}

template<typename Head, typename... Tail>
void Print(Head&& head, Tail&&... tail)
{
  cout << head << "  ";
  Print(forward<Tail>(tail)...);
}

int main()
{
  float pi = 3.1429;
  double q = pi;
  int e = 3;
  int *w = &e;
  const int& p = 3;
  Print(pi, q, w, p);
}

