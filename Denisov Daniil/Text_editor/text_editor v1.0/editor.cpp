#include "editor.h"
int text_editor:: count_words;
std::map<std::string, int>text_editor::fix_word;

text_editor::text_editor(const std::string buf)
{
  original_text = buf;
  std::cout << "***************Начальное предложение***************\n" << original_text << std::endl;
}

void text_editor::add_word(const std::string _rigth)
{
  fix_word[_rigth] = ++count_words;
}


//Исправить
void text_editor::delete_multi_el(const size_t _position, size_t _last_position, size_t& _mult)
{
  if (_position != original_text.npos)
  {
    int lopata = _position;
    while (lopata == _last_position)
    {
      original_text.erase(_last_position, 1);
      lopata = original_text.find_first_of(".!,?", _last_position);
      _mult++;
    }
  }
}

void text_editor::print_paragraphs()
{
  std::cout << "\n***************Отредактированное предложение ***************\n";//Не печатает,потому что нет знаков препинания
  size_t position = 0;
  size_t last_position = 0;
  while (position != finaly_text.npos)
  {
    position = finaly_text.find_first_of("?.!", last_position);
    if (position != finaly_text.npos)
    {

      //Вывод строки до ? . ! включительно и перенос на новую строку
      for (last_position; last_position <= position;)
      {

        std:: cout << finaly_text[last_position];
        if (last_position == position)
          std::cout << std::endl;
        last_position++;

      }
    }
  }
  //Тут можно добавить,если в конце нет знака препинания,то распечатать от последнего знака  до конца
}

void text_editor::find_errors(std::string::iterator& dictionary_it, std::string::iterator& buffer_it,  
 std::string buffer_temp, std::string dictionary_temp,int &prioritet,bool &fix, const size_t last_position)
{
  int errors = 0;
  for (dictionary_it = dictionary_temp.begin(), buffer_it = buffer_temp.begin(); dictionary_it != dictionary_temp.end()
    && buffer_it != buffer_temp.end(); dictionary_it++, buffer_it++)
  {
    if (*dictionary_it != *buffer_it)
    {
      errors++;
    }
  }
  int grabli = (buffer_temp.size() - dictionary_temp.size());
  errors += abs(grabli);//????????????
  if (errors == prioritet && prioritet != max_errors_in_the_word)//Максимум одна опечатка
  {
    fix = true;
    fix_errors(errors, prioritet, buffer_temp, dictionary_temp,last_position);
  }
}

void text_editor::fix_errors(const int errors,int &prioritet,std::string buffer_temp,std::string dictionary_temp,const size_t last_position)
{
    for (int i = 0; i < dictionary_temp.size(); i++)//Замена (неправильного) слова в буфере на (правильное)
    {
        finaly_text.push_back(dictionary_temp[i]);
    }
    //buffer[pref_position + 1] = ' ';
    finaly_text.push_back(original_text[last_position]);// = -= ======================== =
    std::cout << dictionary_temp << ' ';
    prioritet = max_errors_in_the_word;//Если найдено нужно слово из словаря,закончить поиск 
    //Тут должен быть break
}

void text_editor::SetBuff(const std::string temp_buff,const size_t last_position)
{
  for (int i=0; i < temp_buff.size(); i++)
  {
    finaly_text.push_back(temp_buff[i]);
  }
  finaly_text.push_back(original_text[last_position]);
}

int text_editor::GetMaxError()
{
  return max_errors_in_the_word;
}
