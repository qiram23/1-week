#include <iostream>

using namespace std;

class Objects
{
  private:
    static int Counter;
  public:
    Objects(){Counter++;}
    static int getCounter() {return Counter;}
};

int Objects::Counter = 0;

int main()
{
    Objects q, w, e;
    cout << "Number of objects: " << Objects::getCounter() << endl;
    Objects r, t;
    cout << "Number of objects: " << Objects::getCounter() << endl;
    return 0;
}
