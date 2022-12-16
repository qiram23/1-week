#include "figure.h"

const double pi = 3.141592653589793;

using namespace std;

double Circle::square()
{
  return pi * r * r;
}

double Circle::perimeter()
{
  return 2 * pi * r;
}

void Circle::print()
{
  cout << "Figure: Circle;" << endl;
  cout << "Characteristic:" << endl;
  cout << "Radius: " << r << "." << endl;
  cout << "Perimeter: " << perimeter() << "; square: " << square() << ". " << endl;
}
