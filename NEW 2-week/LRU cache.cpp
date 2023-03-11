#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRU
{
private:
  int cap;
  int siZe = 0;
  list<int> prior;
  unordered_map<int,int> arr;
public:
  LRU(int capacity = 10)
  {
    cap = capacity;
  };
  ~LRU()
  {
    arr.clear();
    prior.clear();
    siZe = 0;
    cap = 0;
  };

  int get(int key)
  {
    int el = arr[key];
    if (el)
    {
      prior.remove(key);
      prior.push_back(key);
    }
    return el;
  };
  void put(int key, int value)
  {
    if(arr[key]){prior.remove(key);}
    else if (siZe < cap){siZe++;}
    else
    {
      arr.erase(prior.front());
      prior.pop_front();
      prior.push_back(key);
    }
    prior.push_back(key);
    arr[key] = value;
  };
  void pop(int key)
  {
    arr.erase(key);
    prior.remove(key);
    siZe--;
  }
};

int main()
{
  LRU a(3);
  a.put(1,10);
  a.put(2,20);
  a.put(3,30);
  cout << "first: " << a.get(1) << " " << a.get(2) << " " << a.get(3) << " " << endl;
  cout << endl;

  a.put(4,40);
  cout << "second: " <<  a.get(1) << " " <<  a.get(2) << " " << a.get(3) << " " << a.get(4) << endl;
  cout << endl;

  a.put(2,21);
  a.put(5,50);
  cout << "third: " <<  a.get(2) << " " <<  a.get(3) << " " << a.get(4) << " " << a.get(5) << endl;
  cout << endl;

  a.put(6,60);
  cout << "fourth: " <<  a.get(2) << " " <<  a.get(3) << " " << a.get(4) << " " << a.get(5) << " " << a.get(6) << endl;


}
