#include "editor.h"
int text_editor::count_words;
std::map<std::string, int>text_editor::fix_word;

text_editor::text_editor(const std::string buf)
{
  original_text = buf;
  //Словарь по умолчанию
  add_word("В");
  add_word("лес");
  add_word("лесу");
  add_word("родилась");
  add_word("елочка");
  add_word("она");
  add_word("он");
  add_word("рoсла");
  add_word("Конец");
}

void text_editor::logic(std::string _buffer)
{
  bool change = false;//Нужна ли замена
  int prioritet = 0;//Поиск начинается от минимального количества ошибок
  std::string temp1;//Хранит слово из исходной строки
  std::string temp_dictionary;//Хранит слово из словаря(чтобы сравнивать поэлементно)
  size_t pos = 0;//Позиция элементов переноса на другую строку(пока не npos)
  size_t last_position = 0;//Позиция  знаков окончания предложения
  size_t mult = 0;//Количество знаков препинания подряд
  std::map<std::string, int>::iterator str;//Идёт по словарю
  std::string::iterator it1;//Ходит по элементам слова словаря
  std::string::iterator it2;//Ходит по элементам текущего слова исходной строки

  while (pos != _buffer.npos)//Пока не дошёл до конца буфера
  {
    temp1.clear();//Очистка слова,для записи нового
    pos = _buffer.find_first_of(".!, ?", last_position);//Место следующего знака препинания
    change = false;

    if (pos != last_position)//Если не два знака препинания подряд
    {
      //Пока не сравнено со всеми словами из словаря
      for (str = text_editor::fix_word.begin(); str != text_editor::fix_word.end(); str++)
      {
        //Если не нашёл одинаковых слов,искать с 1 ошибкой и тд..
        if (str == --text_editor::fix_word.end() && prioritet != GetMaxError())
        {
          prioritet++;
          str = text_editor::fix_word.begin();
        }
        //Если количество искомых ошибок не превышает ограничение 
        if (prioritet <= GetMaxError())
        {
          temp_dictionary = (*str).first;
          if (pos != _buffer.npos)//Пока не дошёл до конца буфера
          {
            for (last_position; last_position < pos; last_position++)//Копирует слово из буфера
            {
              temp1.push_back(_buffer[last_position]);
            }
            //Ищет ошибки в скопированном слове и в слове из словаря
            find_errors(it1, it2, temp1, temp_dictionary, prioritet, change, last_position);
          }
        }
      }
      if (!change)//Если не нашёл меняет на такое же
      {
        SetBuff(temp1, last_position);
      }
    }
    last_position++;
    prioritet = 0;
  }
}

void text_editor::Print_origin_text()
{
  std::cout << original_text << std::endl;
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
  std::cout << "\n***************Отредактированное предложение***************\n";
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

        std::cout << finaly_text[last_position];
        if (last_position == position)
          std::cout << std::endl;
        last_position++;

      }
    }
  }
  //Тут можно добавить,если в конце нет знака препинания,то распечатать от последнего знака  до конца
}

void text_editor::find_errors(std::string::iterator& dictionary_it, std::string::iterator& buffer_it,
  std::string buffer_temp, std::string dictionary_temp, int& prioritet, bool& fix, const size_t last_position)
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
  int differ_in_size = (buffer_temp.size() - dictionary_temp.size());
  errors += abs(differ_in_size);
  double temp = (double)errors;
  double temp2 = (double)buffer_temp.size();
  if (errors == prioritet && prioritet != max_errors_in_the_word && (double)(temp / temp2) <= max_koff_errors)//Максимум одна опечатка
  {
    fix = true;
    fix_errors(errors, prioritet, buffer_temp, dictionary_temp, last_position);
  }
}

void text_editor::fix_errors(const int errors, int& prioritet, std::string buffer_temp, std::string dictionary_temp, const size_t last_position)
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

void text_editor::SetBuff(const std::string temp_buff, const size_t last_position)
{
  finaly_text.push_back('*');
  for (int i = 0; i < temp_buff.size(); i++)
  {
    finaly_text.push_back(temp_buff[i]);
  }
  finaly_text.push_back('*');
  finaly_text.push_back(original_text[last_position]);
}

int text_editor::GetMaxError()
{
  return max_errors_in_the_word;
}

bool text_editor::Save_to_file()
{
  system("cls");
  int temp = 1;//Выбор
  std::string word;//Добавленное слово
  std::string path;//Путь
  std::cout << "***************Введите какое название должен иметь файл***************\n";
  std::cin >> path;
  path += ".txt";
  std::ofstream fout;
  std::cout << "Удалить предыдущие данные?(Да - 1,Нет - 0):";
  std::cin >> temp;
  if (temp == 1)
  {
    fout.open(path);
  }
  else if (temp == 0)
  {
    fout.open(path, std::ofstream::app);
  }
  else
  {
    std::cout << "Неверно введены данные!!!" << std::endl;
    return false;
  }

  if (!fout.is_open())
  {
    std::cout << "Не удалось открыть файл!Будет использоваться словарь по умолчанию!" << std::endl;
    return false;
  }
  else
  {
    do
    {
      std::cout << "Введите слово,которое хотите добавить:";
      SetConsoleCP(1251);
      std::cin >> word;
      add_word(word);
      {
        
        fout << word;
        SetConsoleCP(866);
        fout << "\n";
      }
      std::cout << "Добавить ещё слово?(Да - 1,Нет - 0):";
      std::cin >> temp;

    } while (temp != 0);
  }
  fout.close();
  return true;
}

bool text_editor::Get_file_info()
{
  int temp = 1;//Выбор
  std::string str = "a";//Считываемые данные
  std::string path;//Путь
  std::cout << "***************Введите какое название должен иметь файл***************\n";
  std::cin >> path;
  path += ".txt";
  std::ifstream fin;
  fin.open(path);
  if (!fin.is_open())
  {
    std::cout << "Не удалось открыть файл!Будет использоваться словарь по умолчанию!" << std::endl;
    return false;
  }
  else
  {
    std::cout << "Данные из файла!\n";
    //SetConsoleCP(1251);

    while (!fin.eof())
    {
      str = "";
      fin >> str;
      add_word(str);

      std::cout << str << "\n";
    }
    //SetConsoleCP(866);
    std::cout << std::endl;
  }
  fin.close();
  return true;
}

void text_editor::Interface()
{
  int temp = 0;
  std::cout << "Нужен словарь по умолчанию?(1 - да,0 - создать свой):";
  std::cin >> temp;
  if (!temp)
  {
    fix_word.clear();
    text_editor::count_words = 0;
    fix_word[" "]++;
  }

  if (!temp)
  {
    do
    {
      std::cout << "***************Меню***************\n1)Добавить слова в файл и словарь по умолчанию \n2)Посмотреть данные из файла\n"
        << "3)Продолжить\n";
      std::cin >> temp;
      if (temp == 1)
      {
        Save_to_file();
      }
      if (temp == 2)
      {
        Get_file_info();
      }
    } while (temp == 1 || temp == 2);
  }
  else
  {
    do
    {
      std::cout << "***************Меню***************\n1)Добавить слова в файл и словарь по умолчанию \n2)Посмотреть данные из файла\n"
        << "3)Использовать словарь по умолчанию\n4)Продолжить\n";
      std::cin >> temp;
      if (temp == 1)
      {
        Save_to_file();
      }
      if (temp == 2)
      {
        Get_file_info();
      }
    } while (temp == 1 || temp == 2);
  }
}
