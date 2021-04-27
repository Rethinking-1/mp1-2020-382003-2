#include <iostream>
#include<string>
#include<fstream>
#include <map>
#include<Windows.h>
class text_editor
{
private:
  std::string finaly_text;
  static int count_words;//���������� ���� � ������� �� ���������
  const int max_errors_in_the_word = 4;
  const double max_koff_errors = 0.3;//��������� ������ � ����� � ���������� ����
  std::string original_text;
  static std::map<std::string, int>fix_word;//�������
  //������� ����� ����������,������ � ���
  void delete_multi_el(const size_t _position, size_t _last_position, size_t& _mulp);
  //����� ������,��� ������������� �������� fix_errors
  void find_errors(std::string::iterator& dictionary_it, std::string::iterator& buffer_it, std::string buffer_temp, std::string dictionary_temp, int& prioritet, bool& fix, const size_t last_position);
  //��������� ������
  void fix_errors(const int errors, int& prioritet, std::string buffer_temp, std::string dictionary_temp, const size_t last_position);
  //���� ����� �� ��������
  void SetBuff(const std::string temp_buff, const size_t last_position);
public:
  text_editor(const std::string buf);//�����������
  void logic(std::string _buffer);
  void Print_origin_text();
  void add_word(const std::string _rigth);//�������� � �������
  //�������� ����� �� ��������� � �����������
  void print_paragraphs();
  int GetMaxError();
  //������ ����� ���� � �������
  bool Save_to_file();
  //���������� ����� �� �������
  bool Get_file_info();
  void Interface();
};