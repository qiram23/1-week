#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
  private:
    float Re, Im;

  public:
    Complex()
    {
      Re = 0;
      Im = 0;
    }

    Complex(float re, float im)
    {
      Re = re;
      Im = im;
    }

    ~Complex()
    {
    }

    float getRe(){return Re;}
    float getIm(){return Im;}

    Complex operator + (Complex &z)
    {
      return Complex (Re + z.Re, Im + z.Im);
    }
    Complex operator - (Complex &z)
    {
      return Complex (Re - z.Re, Im - z.Im);
    }
    Complex operator * (Complex &z)
    {
      return Complex (Re * z.Re - Im * z.Im, Re * z.Im + Im * z.Re);
    }
    float sqr (Complex &z)
    {
      return (Re * Re + Im * Im);
    }
    Complex operator / (Complex &z)
    {
      if (sqr(z) != 0)
      {
        return Complex((Re * z.Re + Im * z.Im)/sqr(z), (Im * z.Re - Re * z.Im)/sqr(z));
      }
    }
    Complex complexConjugate()
    {
      return Complex (Re, - Im);
    }
    Complex trigForm ()
    {
      double r;
      float p;
      r = sqrt(Re * Re + Im * Im);
      p = atan(Im/Re);
      //cout << "z = " << r << "(cos(" << p << ") + i*sin(" << p <<"))" << endl;
      return Complex (r, p);
    }
    Complex exhibForm ()
    {
      Complex q, z(Re, Im);
      q = z.trigForm();
      //cout << "z = " << q.Re << "exp*(i" << q.Im << ")" << endl;
      return q;
    }
    Complex algebForm()
    {
      float re, im;
      re = Re / sqrt(1 + std::pow(tan(Im), 2));
      im = Re * tan(Im) / sqrt(1 + std::pow(tan(Im), 2));
      return Complex (re, im);
    }
    Complex pow(float n)
    {
      Complex q, z(Re, Im);
      float re, im;
      q = z.trigForm();
      re = std::pow(q.Re, n) * cos (n * q.Im);
      im = std::pow(q.Re, n) * sin (n * q.Im);
      return Complex (re, im);
    }
    Complex rootExtract(float n)
    {
      Complex q, z(Re, Im);
      float re, im;
      q = z.trigForm();
      re = std::pow(q.Re, 1/n) * cos (q.Im / n);
      im = std::pow(q.Re, 1/n) * sin (q.Im / n);
      return Complex (re, im);
    }

  friend ostream & operator<< (ostream &, const Complex &);
  friend istream & operator>> (istream &, Complex &);

};

ostream& operator<< (ostream &cout, const Complex &z)
{
  cout << z.Re << " + i" << z.Im;
  return cout;
}

istream& operator>> (istream &cin, Complex &z)
{
  cin >> z.Re >> z.Im;
  return cin;
}

int main()
{
  Complex a (3, 12);
  Complex b (4, 55);
  Complex c, d;
  c = a.trigForm();

  cout << a + b << endl;
  cout << a - b << endl;
  cout << a * b << endl;
  cout << a / b << endl << endl;

  cout << "trigonometric form: a = " << c.getRe() << "(cos(" << c.getIm() << ") + i*sin(" << c.getIm() <<"))" << endl;
  cout << "exponential form: a = " << c.getRe() << "exp*(i" << c.getIm() << ")" << endl;
  cout << a.pow(2) << endl;
  cout << a.rootExtract(2) << endl;
}
