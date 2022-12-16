#include "figure.h"

using namespace std;

double Square::square()
{
  return a * a;
}

double Square::perimeter()
{
  return 4 * a;
}

void Square::print()
{
  cout << "Figure: Square." << endl;
  cout << "Sides: " << a << "; " << endl;
  cout << "Perimeter: " << perimeter() << "; square: " << square() << ". " << endl;
}
