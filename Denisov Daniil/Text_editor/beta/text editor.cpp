#include <iostream>
#include<string>
//#include<fstream>
#include <map>
//#define test 1
#define ntest 1

using namespace std;
map<string, int>fix_word;//Правильные слова
static int count_words;//Количество слов в словаре
void add_word(string _rigth, map<string, int>& _word)
{
  _word[_rigth]= ++count_words;
}

int main()
{
  setlocale(LC_ALL, "rus");
  int count_fix = 0;//Количество различий в словах
  int prioritet = 0;//Поиск начинается от минимального количества ошибок
  string temp1;//Хранит слово из исходной строки
  string temp_dictionary;//Хранит слово из словаря(чтобы сравнивать поэлементно)
  size_t pos = 0;//Позиция элементов переноса на другую строку(пока не npos)
  size_t last_position = 0;//Позиция  знаков окончания предложения
  size_t pref_position = 0;//Позиция предыдущего знака окончания предложения
  string buffer = "В лесу родилась елычка.В лесу она расла!Ура!";//Исходное предложение
  cout << "***************Начальное предложение***************\n" << buffer;
  map<string, int>::iterator str;//Идёт по словарю
  string::iterator it1;//Ходит по элементам слова словаря
  string::iterator it2;//Ходит по элементам текущего слова исходной строки
  //Словарь
  //Сделать все буквы заглавными при сравнении
  //add_word("Привет", fix_word);
  //add_word("Коля", fix_word);
  //add_word("Как", fix_word);
  //add_word("дела", fix_word);
  //add_word("Конец", fix_word);
  add_word("В", fix_word);
  add_word("лес", fix_word);
  add_word("лесу", fix_word);
  add_word("родилась", fix_word);
  add_word("елочка", fix_word);
  add_word("она", fix_word);
  add_word("он", fix_word);
  add_word("росла", fix_word);
  add_word("Конец", fix_word);
  //=============================================================
#if test 1
  //Сравнивает каждое слово со словами из словаря,если сходятся,выводит
  while (pos != buffer.npos)
  {
    temp1.clear();
    pos = buffer.find_first_of(".!, ?", last_position);
    for (str = fix_word.begin(); str != fix_word.end(); str++)
    {
      // cout << "str " << (*str).first << endl;
      if (pos != buffer.npos)
      {
        for (last_position; last_position < pos; last_position++)
        {
          temp1.push_back(buffer[last_position]);
        }
        if ((*str).first == temp1)
        {
          cout << "temp " << temp1 << endl;
        }
      }
    }
    last_position++;
  }
  //Неотсортирован
 /* for (str = fix_word.begin();str!= fix_word.end(); str++)
  {
    cout << (*str).first<< endl;
  }*/
  cin >> pos;
#endif // test 1
  //==================================================================
#if ntest 1
  cout << "\n***************Слова,взятые из словаря***************\n";
    while (pos != buffer.npos)//Пока не дошёл до конца буфера
    {
      prioritet = 0;
      temp1.clear();//Очистка строки,для записи нового слова
      pos = buffer.find_first_of(".!, ?", last_position);//Место следующего знака препинания


      //Удаление повторяющихся символов
      if (pos != buffer.npos)
      {
        int lopata = pos;
        while (lopata == last_position)
        {
          buffer.erase(last_position, 1);
          lopata = buffer.find_first_of(".!, ?", last_position);
        }
      }
      pref_position = last_position;

      while (prioritet != 2)
      {
        //Пока не сравнено со всеми словами из словаря
        for (str = fix_word.begin(); str != fix_word.end(); str++)
        {
          temp_dictionary = (*str).first;
          if (pos != buffer.npos)//Пока не дошёл до конца буфера
          {
            for (last_position; last_position < pos; last_position++)//Копирует слово из буфера
            {
              temp1.push_back(buffer[last_position]);
            }
            //if(temp1.size()==temp_dictionary.size())
            //Сравнивает слово из буфера со словом из словаря
            for (it1 = temp_dictionary.begin(), it2 = temp1.begin(); it1 != temp_dictionary.end() && (it2) != temp1.end(); it1++, it2++)
            {
              if ((it2) != temp1.end())//Сравнение до конца слова из буфера
              {
                if (*it1 != *it2)
                {//count fix-= abs(it1-it2)
                  count_fix++;
                }
              }
            }

            int grabli = (temp1.size() - temp_dictionary.size());
            count_fix += abs(grabli);//????????????
            //Количество несходств 

            if (count_fix == prioritet)//Максимум одна опечатка
            {
              for (int i = 0;i < temp_dictionary.size(); i++)//Замена (неправильного) слова в буфере на (правильное)
              {
                if (i < temp1.size())
                {
                  //Исправить,чтобы более короткие слова не заменяли правильное слово
                  buffer[pref_position] = temp_dictionary[i];
                  pref_position++;
                }
               /* else
                  temp1.insert(i, temp_dictionary, ++last_position,1);*/
              }
              //buffer[pref_position + 1] = ' ';
              cout << temp_dictionary << ' ';
              prioritet = 1;//Если найдено нужно слово из словаря,закончить поиск 
              break;
            }
            count_fix = 0;
          }
        }
        prioritet++;
      }
      last_position++;
    }
 // }
#endif // test 2
  //=======================================================================
  cout << "\n***************Отредактированное предложение***************\n";
  last_position = 1;
  pos = 0;
  cout << buffer[0];
  //========================================================================
  while (pos != buffer.npos)
  {
    pos = buffer.find_first_of("?.!", last_position);
    if (pos != buffer.npos)
    {

      //Вывод строки до ? . ! включительно и перенос на новую строку
      for (last_position; last_position <= pos;)
      {

        cout << buffer[last_position];
        if (last_position == pos)
          cout << endl;
        last_position++;

      }
    }
  }
  return 0;
}

