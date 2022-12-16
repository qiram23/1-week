#include <iostream>

using namespace std;

template <int n>
struct Fib: Fib<n - 1>
{
protected:
  static const int pre = Fib<n - 1>::value;
public:
  static const int value = Fib<n - 1>::pre + pre;
};

template <> struct Fib <0>
{
protected:
  static const int pre = 0;
public:
  static const int value = 0;
};

template <> struct Fib <1>
{
protected:
  static const int pre = 0;
public:
  static const int value = 1;
};
