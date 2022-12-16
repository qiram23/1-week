#include "figure.h"
#include <cmath>

using namespace std;

double Quadrangle::square()
{
  return sqrt((4 * d1 * d2 - (b * b + d * d - a * a - c * c) * (b * b + d * d - a * a - c * c))/16);
}

double Quadrangle::perimeter()
{
  return a + b + c + d;
}

void Quadrangle::print()
{
  cout << "Figure: Quadrangle." << endl;
  cout << "Sides: " << a << ", " << b << ", " << c << ", " << d << "; " << endl;
  cout << "Diameters: " << d1 << ", " << d2 << "; " << endl;
  cout << "Perimeter: " << perimeter() << "; square: " << square() << ". " << endl;
}
