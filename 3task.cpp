#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, D;
    float x_1, x_2;
    cout << "Enter the coefficients a, b, c: " << endl;
    cin >> a >> b >> c;

    D = b*b - 4*a*c;

    if (D > 0)
    {
        x_1 = (-b+sqrt(D))/(2*a);
        x_2 = (-b-sqrt(D))/(2*a);
        cout << "x_1 = " << x_1 << endl;
        cout << "x_2 = " << x_2 << endl;
    }
    else if (D == 0)
    {
        x_1 = -b/(2*a);
        cout << "x_1 = x_2 = " << x_1 << endl;
    }
    else
    {
        cout << "no solutions" << endl;
    }


    return 0;
}
