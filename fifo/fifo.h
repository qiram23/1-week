#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

template <class T, class container = deque <T>>
class FIFO {
private:
  container container;
public:
  FIFO() = default;

  bool empty() { return !container.size(); }
  void push(const T& a){container.push_back(a);}
  T get()
  {
    if (!empty())
    {
     T temp = container.front();
     container.pop_front();
     return temp;
    }
    else{return NULL;}
  }
};

template <class T>
class FIFO<T, vector<T>>
{
private:
  vector<T> container;

public:
  FIFO() = default;
  bool empty() { return !container.size(); }
  void push(const T& a)
  {
    container.push_back(a);
  }

  T get()
  {
    T temp = container[0];
    for (int i = 0; i < container.size()-1; i++) {container[i] = container[i + 1];}
    container.resize(container.size() - 1);
    return tmp;
  }
};

template<>
class FIFO<char, string> {
private:
  string container;
public:
  FIFO() = default;
  bool empty() { return !container.size(); }
  void push(const char a) {container += a;}
  char get()
  {
    if (!empty())
    {
      char tmp = container[0];
      container = container.substr(1, container.size() - 1);
      return tmp;
    }
    return NULL;
  }
};

#endif // FIFO_H_INCLUDED
