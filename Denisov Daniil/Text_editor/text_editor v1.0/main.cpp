#include"editor.h"
#include"variables.h"
using namespace std;
//������� ��������� ���������� ������ � ���������� ���� � �����(��� ������� ��������)
int main()
{
  setlocale(LC_ALL, "rus");
  std::string buffer = "� ���� �������� �����.....  � ���� ��� �����!.,,�����!";//�������� �����������
  text_editor text(buffer);
  //�������
  text.add_word("�");
  text.add_word("���");
  text.add_word("����");
  text.add_word("��������");
  text.add_word("������");
  text.add_word("���");
  text.add_word("��");
  text.add_word("�����");
  text.add_word("�����");
  //==================================================================
  cout << "\n***************�����,������ �� �������***************\n";
  while (pos != buffer.npos)//���� �� ����� �� ����� ������
  {
    temp1.clear();//������� ������,��� ������ ������ �����
    pos = buffer.find_first_of(".!, ?", last_position);//����� ���������� ����� ����������
    change = false;
   
    //�������� ������������� ��������
    /*text.delete_multi_el(pos, last_position, mult);
    while (mult != 0)
    {
      buffer.erase(last_position, 1);
      mult--;
    }*/
    if (pos != last_position)
    {

      //���� �� �������� �� ����� ������� �� �������
      for (str = text_editor::fix_word.begin(); str != text_editor::fix_word.end(); str++)
      {
        if (str == --text_editor::fix_word.end() && prioritet != text.GetMaxError())
        {
          prioritet++;
          str = text_editor::fix_word.begin();
        }
        if (prioritet <= text.GetMaxError())
        {

          temp_dictionary = (*str).first;
          if (pos != buffer.npos)//���� �� ����� �� ����� ������
          {
            for (last_position; last_position < pos; last_position++)//�������� ����� �� ������
            {
              temp1.push_back(buffer[last_position]);
            }

            text.find_errors(it1, it2, temp1, temp_dictionary, prioritet, change, last_position);
          }
        }
      }
      if (!change)
      {
        text.SetBuff(temp1, last_position);
      }
    }
    last_position++;
    prioritet = 0;
  }
  text.print_paragraphs();
  _getwche();
  return 0;
}