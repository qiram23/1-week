#include "figure.h"

using namespace std;

double Rectangle::square()
{
  return a * b;
}

double Rectangle::perimeter()
{
  return 2 * (a + b);
}

void Rectangle::print()
{
  cout << "Figure: Rectangle." << endl;
  cout << "Sides: " << a << ", " << b << "; " << endl;
  cout << "Perimeter: " << perimeter() << "; square: " << square() << ". " << endl;
}
