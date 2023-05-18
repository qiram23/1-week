#include <iostream>
#include <functional>
#include "strin.h"

using namespace std;

int main(){
    SSO a;
    a = "Hello World";
    cout << a.Size() << endl;
    a.Append(" Goodbye World");
    cout << a.Size()<< endl;
    cout << a.Capacity() << endl;
    return 0;
}
