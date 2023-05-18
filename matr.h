#ifndef MATR_H
#define MATR_H

#include <iostream>
#include <cassert>

using namespace std;

class Matrix
{
  public:
    int Rows, Columns;
    float **mat;

  Matrix(int rows, int columns) : Rows(rows), Columns(columns)
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

  Matrix(const Matrix& q) : Rows(q.Rows), Columns(q.Columns)
  {
    newMatrix();
    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        mat[i][j] = move(q.mat[i][j]);
      }
    }
  }

  ~Matrix()
  {
    for (int i = 0; i < Rows; ++i)
    {
      delete[] mat[i];
    }
     delete[] mat;
  }

  void SizeCheck(const Matrix& q)
  {
    assert(Rows == q.Rows);
    assert(Columns == q.Columns);
  }

  void newMatrix()
  {
    mat = new float*[Rows];
    for (int i = 0; i < Rows; ++i)
    {
      mat[i] = new float[Columns];
    }
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

  float& operator()(int x, int y)
  {
    return mat[x][y];
  }

  void set_(int x, int y, float val)
  {
    mat[x][y] = val;
  }

  Matrix& operator = (const Matrix& q)
  {
    if (this == &q)
    {
      return *this;
    }
    SizeCheck(q);
    for (int i = 0; i < Rows; ++i)
    {
      delete[] q.mat[i];
    }
    delete[] q.mat;

    Rows = q.Rows;
    Columns = q.Columns;
    newMatrix();

    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        mat[i][j] = q.mat[i][j];
      }
    }
    return *this;
  }

  Matrix operator + (const Matrix& q)
  {
    SizeCheck(q);
    Matrix c(Rows, Columns);
    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        c.mat[i][j] = q.mat[i][j] + mat[i][j];
      }
    }
    return move(c);
  }

  Matrix operator - (const Matrix& q)
  {
    SizeCheck(q);
    Matrix c(Rows, Columns);
    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < Columns; ++j)
      {
        c.mat[i][j] = mat[i][j] - q.mat[i][j];
      }
    }
    return move(c);
  }

  Matrix operator * (const Matrix& q)
  {
    assert (Columns == q.Rows);
    Matrix c(Rows, q.Columns);
    for (int i = 0; i < Rows; ++i)
    {
      for (int j = 0; j < q.Columns; ++j)
      {
        for (int k = 0; k < Columns; ++k)
        {
          c.mat[i][j] += (mat[i][k] * q.mat[k][j]);
        }
      }
    }
    return move(c);
  }
};

#endif // MATR_H
