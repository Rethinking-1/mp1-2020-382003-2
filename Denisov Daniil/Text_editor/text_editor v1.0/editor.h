#include <iostream>
#include<string>
//#include<fstream>
#include <map>
class text_editor
{

  std::string finaly_text;
  static int count_words;//Количество слов в словаре
  const int max_errors_in_the_word=3;
public:
  std::string original_text;
  static std::map<std::string, int>fix_word;//Словарь
  text_editor(const std::string buf);//конструктор
  void add_word(const std::string _rigth);//Добавить в словарь
    //Удалить знаки препинания,идущие в ряд
  void delete_multi_el(const size_t _position,size_t _last_position,size_t &_mulp);
  //Поделить текст на параграфы и распечатать
  void print_paragraphs();
   //Поиск ошибок
  void find_errors(std::string::iterator& dictionary_it, std::string::iterator& buffer_it, std::string buffer_temp, std::string dictionary_temp,int &prioritet,bool &fix, const size_t last_position);
  //Исправить ошибки
  void fix_errors(const int errors, int& prioritet, std::string buffer_temp, std::string dictionary_temp, const size_t last_position);
  //Если слово не меняется
  void SetBuff(const std::string temp_buff,const size_t last_position);
  int GetMaxError();
};