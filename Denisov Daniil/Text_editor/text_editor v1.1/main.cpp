#include"editor.h"
using namespace std;
//������� ��������� ���������� ������ � ���������� ���� � �����(��� ������� ��������)
//�� ����������-��������� ������� ��������� 
int main()
{
  SetConsoleCP(866);//�� ������ ���������� �������� ��������� �� ����� ��������� ���������
  setlocale(LC_ALL, "rus");
  std::string buffer = "� ���� �������� �����.....  � ���� ��� �����!.,,���!";//�������� �����������
  text_editor text(buffer);
  text.Interface();
  cout << "***************��������� �����������***************\n";
  text.Print_origin_text();
  cout << "\n***************�����,������ �� �������***************\n";
  text.logic(buffer);
  text.print_paragraphs();
  _getwche();
  return 0;
}