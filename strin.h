#ifndef STRIN_H
#define STRIN_H

#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class SSO
{
public:
  size_t size_ = 0;
  size_t capacity = 16;

  union
  {
    char* ptr;
    char bufer[16];
  }value;

  SSO(){}
  SSO(const char* str)
  {
    Copy(str);
  }
  SSO(const SSO& str)
  {
    if (str.capacity > 16)
    {
      Copy(str.value.ptr);
    }
    else
    {
      Copy(str.value.bufer);
    }
  }

  ~SSO()
  {
    if (capacity > 16)
    {
      delete[] value.ptr;
    }
  }

  SSO& operator = (const SSO& str)
  {
    if (str.capacity < 16)
    {
      Copy(str.value.ptr);
    }
    else
    {
      Copy(str.value.bufer);
    }
    return *this;
  }

  size_t Size()const {return size_;}

  void Reserve(size_t capac)
  {
    if ((size_ <= capacity) or (size_ < 16))
    {
      return;
    }
    capac *= 2;
    char* new_ = new char[capac];
    if (capacity > 16)
    {
      copy(value.ptr, value.ptr + size_, new_);
      delete[] value.ptr;

    }
    else
    {
      copy(value.bufer, value.bufer + size_, new_);
    }
    value.ptr = new_;
    capacity = capac;
  }

  size_t Capacity() const
  {
    return capacity;
  }

  void Append(const char* str)
  {
    size_ = strlen(str) + size_ + 1;
    Reserve(size_);
    if (capacity > 16)
    {
      copy(str, str + size_, value.ptr + strlen(str));
    }
    else
    {
      copy(str, str + size_, value.bufer + strlen(str));
    }
  }

  char& operator[](size_t i)
  {
    if (capacity > 16)
    {
      return value.ptr[i];
    }
    else
    {
      return value.bufer[i];
    }
  }
  char& operator[](int i)
  {
    if (capacity > 16)
    {
      return value.ptr[i];

    }
    else
    {
      return value.bufer[i];
    }
  }

  void Copy(const char* str)
  {
    size_t len = strlen(str) + 1;
    Reserve(size_);
    if (capacity > 16)
    {
      copy(str, str + len, value.ptr);
    }
    else
    {
      copy(str, str + len, value.bufer);
    }
    size_ = len;
  }
};

#endif // STRIN_H
