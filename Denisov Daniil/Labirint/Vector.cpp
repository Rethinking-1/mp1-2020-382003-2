#include "Vector.h"
const int _RAND_MAX = 500;
myVector::myVector(int n)
{
  try
  {
    size = n;
    vect = new char[size];
  }
  catch (...)
  {
    cout << "Vector is NOT CREATED!!!" << endl;
  }
}

myVector::myVector(const myVector& v2)
{
  size = v2.size;
  vect = new char[size];
  for (int i = 0; i < size; i++) {
    vect[i] = v2.vect[i];
  }
}

myVector::~myVector()
{
  delete[] vect;//?
  vect = nullptr;
}

void myVector::init()
{
  for (int i = 0; i < size; i++)
  {
    vect[i] = rand() % _RAND_MAX;
  }
}

myVector& myVector::operator=(const myVector& v2)
{
  if (this == &v2)
    return *this;
  delete[] vect;
  vect = new char[v2.size];
  size = v2.size;
  for (int i = 0; i < size; i++) {
    vect[i] = v2.vect[i];
  }
  return *this;
}

char& myVector::operator[](int ind)
{
  if (ind > size)
    throw std::exception();
  return vect[ind];
}



ostream& operator<<(ostream& stream, const myVector& vec)
{
  cout << "___";
  for (int i = 0; i < vec.size; i++) {
    stream << vec.vect[i] << setfill('_') << setw(3);
  }
  return stream;
}
