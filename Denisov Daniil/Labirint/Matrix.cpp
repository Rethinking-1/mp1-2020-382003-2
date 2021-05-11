#include "Matrix.h"
#include<cmath>

Matrix::Matrix(int n)
{
  try
  {
    size = n;

    matr = new myVector[size];
    for (int i = 0; i < size; i++)
    {
      myVector a(size);
      matr[i] = a;//myVector(size);
    }
  }
  catch (...)
  {
    cout << "LABIRINT IS NOT CREATED!!!" << endl;
  }
}

Matrix::Matrix(const Matrix& m1)
{
  size = m1.size;
  matr = new myVector[size];
  for (int i = 0; i < size; i++)
  {
    matr[i] = myVector(size);
  }

  for (int i = 0; i < size; i++)
  {
    matr[i] = m1.matr[i];
  }
}

Matrix::~Matrix()
{
  delete[] matr;
  matr = nullptr;
}

bool Matrix::check_free(int _i, int _j)
{
  for (int i = 0; i < size; i++)
  {
    if (i != _i)
      if (matr[i][_j] == '1')
        return true;
  }
  for (int i = 0; i < size; i++)
  {
    if (i != _j)
      if (matr[_j][i] == '1')
        return true;
  }
  return false;
}

void Matrix::generate()
{
  int put_block;
  int temp1, temp2;
  int count=0;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (i == 0 || j == 0 || i == (size - 1) || j == (size - 1)) {
        matr[i][j] = '#';
      }
      else if (i == 1 && j == 1) {
        matr[i][j] = '~';
      }
      else if (i == (size - 2) && j == (size - 2)) {
        matr[i][j] = '1';
      }
      else
      {
        put_block = rand() %2+1;
        if (put_block == 1)
          matr[i][j] = '1';
        else
          if (check_free(i, j))         
              matr[i][j] = '0';
          else
            matr[i][j] = '1';
      }
    }
  }
  for (int i = 1; i < size-1; i++)
  {
    for (int j = 1; j < size-1; j++)
    {
      if ((matr[i][j] == '1' || matr[i][j] == '~') && matr[i + 1][j] == '0' && matr[i][j + 1] == '0')
      {
        if (count % 2 == 1)
          matr[i + 1][j] = '1';
        else
          matr[i][j + 1] = '1';
        count++;
      }
    }
  }
  cout << "==========\tLABIRINT\t==========\n" << *this << endl;
}



Matrix& Matrix::operator=(const Matrix& m2)
{
  if (this == &m2)
    return *this;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      matr[i][j] = m2.matr[i][j];
    }
  }
  return *this;
}


ostream& operator<<(ostream& stream, const Matrix& matrix)
{
  for (int i = 0; i < matrix.size; i++)
  {
    stream << matrix.matr[i] <<  endl;
  }
  return stream;
}


bool Matrix::labirint()
{
  bool backX = false;
  bool backY = false;
  Matrix temp = *this;
  bool finish = false;
  Way.x[0] = 1;
  Way.y[0] = 1;
  Way.val = 1;
  Way.last_positionY = 1;
  Way.last_positionX = 1;
  while (!finish)
  {
    //way.x[..] = -1; if(!-1) // Не повторять точек,в которых уже был
    //Не заходит в этот блок
    if (!backY && temp.matr[Way.last_positionY + 1].vect[Way.last_positionX] == '1')
    {
      temp.matr[Way.last_positionY + 1][Way.last_positionX] = '~';
      Way.x[Way.last_positionX] = Way.last_positionX;
      Way.y[Way.last_positionY + 1] = ++Way.last_positionY;
      Way.val++;
      if (backX)
        backX = false;
    }

    else if (!backX && temp.matr[Way.last_positionY].vect[Way.last_positionX + 1] == '1')
    {
      temp.matr[Way.last_positionY][Way.last_positionX + 1] = '~';
      Way.x[Way.last_positionX + 1] = ++Way.last_positionX;
      Way.y[Way.last_positionY] = Way.last_positionY;
      Way.val++;
      backY = false;
    }
    else if ((temp.matr[Way.last_positionY].vect[Way.last_positionX - 1] == '1' || temp.matr[Way.last_positionY].vect[Way.last_positionX - 1] == '~')
      && (!(temp.matr[Way.last_positionY - 1].vect[Way.last_positionX] == '1' || temp.matr[Way.last_positionY - 1].vect[Way.last_positionX] == '~')))
    {
      temp.matr[Way.last_positionY][Way.last_positionX - 1] = '~';

      if (temp.matr[Way.last_positionY-1][Way.last_positionX] != '~'&& temp.matr[Way.last_positionY+1][Way.last_positionX] != '~' && temp.matr[Way.last_positionY][Way.last_positionX+1] != '~')
      {
        temp.matr[Way.last_positionY][Way.last_positionX] = matr[Way.last_positionY][Way.last_positionX];
      }

      if (temp.matr[Way.last_positionY - 1][Way.last_positionX - 1] == '~')
      {
        temp.matr[Way.last_positionY - 1][Way.last_positionX] = matr[Way.last_positionY - 1][Way.last_positionX];
        temp.matr[Way.last_positionY + 1][Way.last_positionX] = matr[Way.last_positionY+ 1][Way.last_positionX];
        temp.matr[Way.last_positionY][Way.last_positionX] = matr[Way.last_positionY][Way.last_positionX];
      }



      //if (temp.matr[Way.last_positionY].vect[Way.last_positionX + 1] != '~' && temp.matr[Way.last_positionY + 1].vect[Way.last_positionX] != '~' && temp.matr[Way.last_positionY - 1].vect[Way.last_positionX] != '~')
      //  temp.matr[Way.last_positionY][Way.last_positionX] = '1';

      //if ((matr[Way.last_positionY][Way.last_positionX + 1] != '1' && temp.matr[Way.last_positionY - 1].vect[Way.last_positionX] /**/ != '~') || temp.matr[Way.last_positionY - 1][Way.last_positionX - 1] == '~')
      //  temp.matr[Way.last_positionY - 1][Way.last_positionX] = matr[Way.last_positionY - 1][Way.last_positionX];


      Way.x[Way.last_positionX - 1] = --Way.last_positionX;
      Way.y[Way.last_positionY] = Way.last_positionY;
      Way.val++;
      backX = true;
      backY = false;
    }
    else if (temp.matr[Way.last_positionY - 1].vect[Way.last_positionX] == '1'|| temp.matr[Way.last_positionY - 1].vect[Way.last_positionX] == '~')
    {
      temp.matr[Way.last_positionY - 1][Way.last_positionX] = '~';

      if (temp.matr[Way.last_positionY][Way.last_positionX-1] != '~' && temp.matr[Way.last_positionY][Way.last_positionX+1] != '~'&& temp.matr[Way.last_positionY+1][Way.last_positionX]!='~')
      {
        temp.matr[Way.last_positionY][Way.last_positionX] = matr[Way.last_positionY][Way.last_positionX];
      }

      if (temp.matr[Way.last_positionY - 1][Way.last_positionX - 1] == '~')
      {
        temp.matr[Way.last_positionY][Way.last_positionX - 1] = matr[Way.last_positionY][Way.last_positionX - 1];
        temp.matr[Way.last_positionY][Way.last_positionX +1] = matr[Way.last_positionY][Way.last_positionX +1];
        temp.matr[Way.last_positionY][Way.last_positionX] = matr[Way.last_positionY][Way.last_positionX];
      }

     // if(temp.matr[Way.last_positionY + 1].vect[Way.last_positionX] != '~' && temp.matr[Way.last_positionY].vect[Way.last_positionX+1] != '~' && temp.matr[Way.last_positionY].vect[Way.last_positionX-1] != '~')
     // temp.matr[Way.last_positionY][Way.last_positionX] = '1';

     //if(((matr[Way.last_positionY+1][Way.last_positionX]!='1'&& temp.matr[Way.last_positionY].vect[Way.last_positionX-1]/**/!='~') || temp.matr[Way.last_positionY - 1][Way.last_positionX - 1])=='~')
     // temp.matr[Way.last_positionY][Way.last_positionX-1] = matr[Way.last_positionY][Way.last_positionX - 1];

      Way.x[Way.last_positionX] = Way.last_positionX;
      Way.y[Way.last_positionY - 1] = --Way.last_positionY;
      Way.val++;
      backY = true;
      backX = false;
    }
    else
    {
      cout << "Way is't make out!";
      return false;
    }
    if (temp.matr[size - 2].vect[size - 2] == '~')
    {
      finish = true;
      // cout << "temp\n" << temp;
      *this = temp;
     // Way_back(temp);
      cout << "==========\tWay\t============\n" << *this;
      return true;
    }
  //  cout << "temp\n" << temp;
   //_getwche();

  }
}
bool Matrix::Way_back(Matrix _temp)
{
  //int del = 0;
  //for (int i = 1; i < size; i++)
  //{
  //  for (int j = 1; j < size; j++)
  //  {
  //    del = 0;
  //    if (matr[i][j] == '~')
  //    {
  //      if (matr[i][j + 1] == '~')
  //      {
  //        del++;
  //      }
  //      if (matr[i][j -1] == '~')
  //      {
  //        del++;
  //      }
  //      if (matr[i+1][j] == '~')
  //      {
  //        del++;
  //      }
  //      if (matr[i-1][j] == '~')
  //      {
  //        del++;
  //      }
  //      if (del == 1&&!(i==1&&j==1))
  //      {
  //        matr[i][j] = '1';
  //      }
  //    }
  //  }
  //  matr[size - 2][size - 2] = '~';
  //}
  return true;
}