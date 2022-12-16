#include "figure.h"
#include <cmath>

using namespace std;

double Triangle::square()
{
  return sqrt(p * (p - a) * (p-b) * (p - c));
}

double Triangle::perimeter()
{
  return a + b + c;
}

void Triangle::print()
{
  cout << "Figure: Triangle." << endl;
  cout << "Sides: " << a << ", " << b << ", " << c << "; " << endl;
  cout << "Perimeter: " << perimeter() << "; square: " << square() << ". " << endl;
}
