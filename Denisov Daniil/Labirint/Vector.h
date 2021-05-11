#ifndef _VECTOR_H
#define _VECTOR_H
#include<iostream>
#include<iomanip>
using namespace std;

class myVector
{
public:
  char* vect;
  int size;
  myVector(int n = 1);//?
  myVector(const myVector& m2);
  ~myVector();
  void init();
  char& operator[](int ind);
  myVector&operator=(const myVector& v2);
  friend ostream& operator<<(ostream& stream, const myVector& vec);
};
#endif