#include "figure.h"

const double pi = 3.141592653589793;

using namespace std;

double Ellipse::square()
{
  return pi * a * b;
}

double Ellipse::perimeter()
{
  return (4 * pi * a * b + (a * b) * (a - b))/(a + b);
}

void Ellipse::print()
{
  cout << "Figure: Ellipse;" << endl;
  cout << "Characteristic:" << endl;
  cout << "Semiaxis: " << a << ", " << b << ". " << endl;
  cout << "Perimeter: " << perimeter() << "; square: " << square() << ". " << endl;
}
