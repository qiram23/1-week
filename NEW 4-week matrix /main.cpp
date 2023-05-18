#include <iostream>
#include <functional>
#include "matr.h"

using namespace std;

/*Matrix&& Transpose(Matrix q)
  {
    Matrix c(q.Columns, q.Rows);

    for (int i = 0; i < q.Rows; ++i)
    {
      for (int j = 0; j < q.Columns; ++j)
      {
        c.mat[j][i] = q.mat[i][j];
      }
    }
    c.Print();
    return move(c);
  }*/

int main(){

  Matrix<3, 2, int> a, b;
  Matrix<2, 4, int> c;
  Matrix<2, 4, int> e, d;

  a.set_(0, 0, 1);
  a.set_(1, 1, 2);
  a.set_(2, 0, 3);
  a.set_(2, 1, 4);
  cout << "a:" << endl;
  a.Print();
  cout << endl;

  b.set_(0, 0, 2);
  b.set_(1, 0, 5);
  b.set_(0, 1, 3);
  cout << "b:" << endl;
  b.Print();
  cout << endl;

  c.set_(0, 0, 1);
  c.set_(0, 1, 1);
  c.set_(1, 2, 1);
  cout << "c:" << endl;
  c.Print();
  cout << endl;

  cout << "a + b:" << endl;
  (a + b).Print();
  cout << endl;

  cout << "a * c:" << endl;
  (a * c).Print();
  cout << endl;

  e.set_(0, 0, 1);
  e.set_(0, 1, 2);
  e.set_(0, 2, 3);
  e.set_(1, 0, 4);
  e.set_(1, 1, 5);
  e.set_(1, 2, 6);
  e.set_(2, 0, 7);
  e.set_(2, 1, 8);
  e.set_(2, 2, 9);

  cout << "e:" << endl;
  e.Print();
  cout << endl;

  /*cout << "Transpose e:" << endl;*/
  //d = Transpose(e);



}
