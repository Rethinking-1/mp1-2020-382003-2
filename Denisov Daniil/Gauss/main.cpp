#include "Class.h";
int main()
{
  int temp;
  int width, high;
  setlocale(LC_ALL, "rus");
  cout << "������� ���������� �����:";
  cin >> high;
  cout << "������� ���������� �������������:";
  cin >> width;
  matrixs m(high, width);
  do
  {
    cout << "������ ��������(1) ��� ��������� �������������(2)? ";
    cin >> temp;
  } while (temp != 1 && temp != 2);
  if (temp == 1)
  {
    for (int i = 0; i < high; i++)
    {
      for (int j = 0; j < width; j++)
      {
        m.SetEl(m,i,j);
      }
    }
  }
  if (temp == 2)
  {
    m.zapolnenie();
  }

  cout << "���� �������" << endl;
  m.print();

  cout << endl << "����� ������" << endl;
  m.method_gausa();

  cout << "�����" << endl;
  m.print();
  return 0;
}