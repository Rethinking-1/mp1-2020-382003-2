#include"Matrix.h"
#include "Vector.h"
int main()
{
  setlocale(LC_ALL, "rus");
  srand(time(NULL));
  int size;
  cout << "What is the size of the labirint?";
  cin >> size;
  Matrix m1(size);
  m1.generate();
  m1.labirint();
  _getwche();
  return 0;
}