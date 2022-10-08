#include <iostream>

using namespace std;

void f(int i) {cout << "int " << i << "\n";}
void f(double d ) {cout << "double " << d << "\n";}

int main()
{
    // f(); - выдает ошибку


    f(4); // 1 решение
    f(4.6);


    int x = 1 ; //2 решение
    double y = 2;

    f(x);
    f(y);


    return 0;
}
