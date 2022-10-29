#include <iostream>

using namespace std;

class Fraction
{
private:
  float numer; //÷èñëèòåëü
  unsigned int denom; //çíàìåíàòåëü
public:
  Fraction ()
  {
    numer = 0;
    denom = 1;
  }
  Fraction (float n)
  {
    numer = n;
    denom = 1;
  }
  Fraction (float n, int d)
  {
    numer = n;
    denom = d;
  }
  ~Fraction()
  {
  }

  float getNumer() {return numer;}
  int getDenom() {return denom;}

  int NOD (int n, int m)
  {
    int div;
    if (n == m) return n;
    int a;
    if (n > m)
    {
      a = n - m; div = NOD (n, a);
    }
    else
    {
      a = m - n; div = NOD (m, a);
    }
    return div;
  }
  int NOK (int n, int m)
  {
    return n*m / NOD (n, m);
  }

  Fraction reduce () //ñîêðàùåíèå äðîáè
  {
  }

  Fraction operator + (Fraction &a)
  {
    int nok = NOK (denom, a.denom);
    float num, anum;
    int den, aden;
    num = numer * (nok / denom);
    anum = a.numer * (nok / a.denom);
    return Fraction (num + anum, nok);
  }

  Fraction operator - (Fraction &a)
  {
    int nok = NOK (denom, a.denom);
    float num, anum;
    int den, aden;
    num = numer * (nok / denom);
    anum = a.numer * (nok / a.denom);
    return Fraction (num - anum, nok);
  }

  Fraction operator * (Fraction &a) {return Fraction (numer * a.numer, denom * a.denom);}
  Fraction operator / (Fraction &a) {return Fraction (numer * a.denom, denom * a.numer);}

  double fracToDouble()
  {
    return numer/denom;
  }

  friend ostream & operator<< (ostream &, const Fraction &);
  friend istream & operator>> (istream &, Fraction &);

};

ostream& operator<< (ostream &cout, const Fraction &a)
{
  cout << a.numer << "/" << a.denom;
  return cout;
}

istream& operator>> (istream &cin, Fraction &a)
{
  cin >> a.numer >> a.denom;
  return cin;
}

int main()
{
  Fraction a(10, 12);
  Fraction b(3,4);
  cout << a*b << endl;
  cout << a.fracToDouble() << endl;
  return 0;
}
