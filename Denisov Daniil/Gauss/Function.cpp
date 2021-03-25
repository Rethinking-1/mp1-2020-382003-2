#include "Class.h"
matrixs::matrixs(const int phigh, const int pwidth)
{
  high = phigh;
  width = pwidth;
  matrix = new double* [high];
  for (int i = 0; i < high; i++)
	this->matrix[i] = new double[width];
}

void matrixs::zapolnenie()
{
  for (int i = 0; i < this->high; i++)
  {
	  for (int j = 0; j < this->width; j++)
	  {
		  this->matrix[i][j] = (double)rand() / RAND_MAX * (100.0 - 0.01) + 0.01;
	  }
  }
}

void matrixs::print()
{
  for (int i = 0; i < high; i++)
  {
	for (int j = 0; j < width; j++)
	{
	  cout << setfill('_') << setw(12) << matrix[i][j];
	}
	cout << endl;
  }
}

matrixs& matrixs::operator=(const matrixs& m)
{
  if (this == &m)
	return *this;
  //������������ � ������������� ������
  for (int i = 0; i < m.high; i++)
  {
	delete[]matrix[i];
  }
  delete[]matrix;
  high = m.high;
  width = m.width;
  matrix = new double* [high];
  //������������ 
  for (int i = 0; i < high; i++)
  {
	matrix[i] = new double[width];
  }
  for (int i = 0; i < m.high; i++)
  {
	for (int j = 0; j < m.width; j++)
	{
	  this->matrix[i][j] = m.matrix[i][j];
	}
  }
  return *this;
}

matrixs& matrixs::operator*(const int a)//�������� ������ � �� 1/[a][a]
{
  if (fabs(matrix[a][a]) > 1e-14)
  {
	double temp = matrix[a][a];
	for (int i = 0; i < width; i++)
	{
	  matrix[a][i] = matrix[a][i] * (1 / temp);
	}
	return *this;
  }
}

matrixs& matrixs::operator+(const int str)
{
  bool str1 = false;
  double temp;//=��������� ���� � ���� ������ � ������� ��������
  double* temp_mat;//����� �� �������� ������ ��� ������ � ������� ��������
  temp_mat = new double[width];
  for (int i = -str; i < high - str - 1; i++)
  {
	if (str != 0 && !str1)//�������
	{
	  for (int m = 0; m < width; m++)
	  {
		temp_mat[m] = matrix[str][m];
	  }
	  temp = matrix[0][str];
	  for (int k = 0; k < width; k++)
	  {
		temp_mat[k] *= temp;
	  }
	  if (temp_mat[str] != -temp)
	  {
		for (int j = 0; j < width; j++)
		{
		  temp_mat[j] *= -1;
		}
	  }
	  for (int j = 0; j < width; j++)
		matrix[0][j] += temp_mat[j];
	  str1 = true;
	}
	//���������� ������ � ������� �������� � ������
	for (int m = 0; m < width; m++)
	{
	  temp_mat[m] = matrix[str][m];
	}
	temp = matrix[str + 1 + i][str];

	for (int k = 0; k < width; k++)
	{
	  temp_mat[k] *= temp;
	}

	if (temp_mat[str] != -temp)
	{
	  for (int j = 0; j < width; j++)
	  {
		temp_mat[j] *= -1;
	  }
	}
	//��������� �������� ������� � ������� ��������
	for (int j = 0; j < width; j++)
	{
	  if ((str + 1 + i) != str)
		matrix[str + 1 + i][j] += temp_mat[j];
	}

  }
  delete[]temp_mat;
  return *this;
}
void matrixs::SetEl(matrixs& m, const int line, const int column)
{
  double element;
  if (m.width != column + 1)
  {
	cout << "������� " << line + 1 << " �����, " << column + 1 << " ���������:";
  }
  else
  {
	cout << "������� ���� ����� " << line + 1 << " ���������:";
  }
  cin >> element;
  m.matrix[line][column] = element;
}