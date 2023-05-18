#ifndef MATR_H
#define MATR_H

#include <iostream>
#include <cassert>

using namespace std;

template <unsigned Rows, unsigned Columns, typename T = float>

class Matrix
{
  public:
    static const int Rows_ = Rows;
    static const int Columns_ = Columns;
    T  **mat;


  Matrix()
    {
      newMatrix();
        for (int i = 0; i < Rows; ++i)
        {
            for (int j = 0; j < Columns; ++j)
            {
                mat[i][j] = 0;
            }
        }
    }

  void SizeCheck(const Matrix& q)
  {
    assert(Rows_ == q.Rows_);
    assert(Columns_ == q.Columns_);
  }

  void newMatrix()
  {
    mat = new int*[Rows];
    for (int i = 0; i < Rows; ++i)
    {
      mat[i] = new int[Columns];
    }
  }

  void set_(int x, int y, float val)
  {
    mat[x][y] = val;
  }

  void Print()
  {
    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
  }

  T& operator()(int x, int y)
  {
    return mat[x][y];
  }

  Matrix<Rows, Columns, T>& operator = (const Matrix<Rows, Columns, T>& q)
  {
    if (this == &q)
    {
      return *this;
    }
    newMatrix();

    Rows = q.Rows;
    Columns = q.Columns;

    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        mat[i][j] = q.mat[i][j];
      }
    }
    return *this;
  }

  Matrix<Rows, Columns, T> operator + (const Matrix<Rows, Columns, T>& q)
  {
    SizeCheck(q);
    Matrix<Rows, Columns, T> c;
    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        c.mat[i][j] = q.mat[i][j] + mat[i][j];
      }
    }
    return c;
  }

  Matrix<Rows, Columns, T> operator - (const Matrix<Rows, Columns, T>& q)
  {
    SizeCheck(q);
    Matrix<Rows, Columns, T> c;
    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        c.mat[i][j] = mat[i][j] - q.mat[i][j];
      }
    }
    return c;
  }

  template<unsigned L, unsigned M, unsigned R, typename T_ = float>
  Matrix<L, R, T> operator * (const Matrix<L, M, T>& q)
  {
    Matrix<L, R, T> c;
    for (int i = 0; i < L; ++i)
    {
      for (int j = 0; j < R; ++j)
      {
        for (int k = 0; k < M; ++k)
        {
          c.mat[i][j] += (mat[i][k] * q.mat[k][j]);
        }
      }
    }
    c.Print();
  }
};

#endif // MATR_H
