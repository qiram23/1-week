#ifndef FIGURE_H
#define FIGURE_H


class Figure
{
public:
  virtual double square();
  virtual double perimeter();
  virtual print();

protected:
  double const pi = 3,1415926535;

} ;

class Polygon : Figure
{
};

class Ellipse : Figure
{
private:
  double a, b;

public:
  double square(double a, b);
  double perimeter(double a, b);
  void print(a, b);
};

class Circle : Ellipse
{
private:
  double r;

public:
  double square(double r);
  double perimeter(double r);
  void print(r);
};

class Quadrangle : Polygon
{
private:
  double d1, d2, a, b, c, d;

public:
  double square (double d1, d2, a, b, c, d);
  double perimeter (double a, b, c, d);
  void print(d1, d2, a, b, c, d);
};

class Triangle : Polygon
{
private:
  double a, b, c;
  double p = (a + b + c)/2;

public:
  double square (double p, a, b, c);
  double perimeter (double a, b, c);
  void print(a, b, c, d);
};

class Rectangle : Quadrangle
{
private: double a, b;

public:
  double square(double a, b)
  double perimeter(double a, b)
};

class Square : Rectangle
{
private: double a;

public:
  double square(double a);
  double perineter(double a);

class Point : Figure
{
private: double x, y;

public:
  void print (x, y);

};

#endif // FIGURE_H
