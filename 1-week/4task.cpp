#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cout << "Enter the x and y values: " << endl;
    cin >> x >> y;

    x += y; // = x + y
    y = x - y; // = x
    x -=y; // = y

    cout << "Resulting x and y: " << x << ", " << y << endl;
    return 0;
}
