#pragma once
#include"Vector.h"
#include "Point.h"

class Matrix
{
  myVector* matr, * matr_solution;//A
  myPoint Way;
  int size;
public:
  Matrix(int n);
  Matrix(const Matrix& m2);
  Matrix& operator=(const Matrix& m2);
  friend ostream& operator<<(ostream& stream, const Matrix& matrix);
  ~Matrix();//����������
  bool labirint();
  bool Way_back(Matrix _temp);
  void generate();//������
  bool check_free(int _i,int _j);//��������� �� ������ ����� ��������� �����
};
