#include<iostream>
#include <iomanip>
using namespace std;
class matrixs
{
private:
  int width, high;
  double** matrix;
public:
  matrixs(const int phigh, const int pwidth);//�������� �������
  void zapolnenie();
  void print();
  matrixs& operator=(const matrixs& m);//�� ������������
  matrixs& operator*(const int a);//�������� ������� ������� � ������� [a][a]
  matrixs& operator+(/**/const int str);//�������� ������� �
  matrixs& method_gausa();
  void SetEl(matrixs&m,const int line,const int column);
};
