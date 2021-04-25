#include"editor.h"
#include"variables.h"
using namespace std;
//Сделать отношение количества ошибок к количеству букв в слове(для большей точности)
int main()
{
  setlocale(LC_ALL, "rus");
  std::string buffer = "В лису радияась елочк.....  В лесу она росла!.,,Урааа!";//Исходное предложение
  text_editor text(buffer);
  //Словарь
  text.add_word("В");
  text.add_word("лес");
  text.add_word("лесу");
  text.add_word("родилась");
  text.add_word("елочка");
  text.add_word("она");
  text.add_word("он");
  text.add_word("росла");
  text.add_word("Конец");
  //==================================================================
  cout << "\n***************Слова,взятые из словаря***************\n";
  while (pos != buffer.npos)//Пока не дошёл до конца буфера
  {
    temp1.clear();//Очистка строки,для записи нового слова
    pos = buffer.find_first_of(".!, ?", last_position);//Место следующего знака препинания
    change = false;
   
    //Удаление повторяющихся символов
    /*text.delete_multi_el(pos, last_position, mult);
    while (mult != 0)
    {
      buffer.erase(last_position, 1);
      mult--;
    }*/
    if (pos != last_position)
    {

      //Пока не сравнено со всеми словами из словаря
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
          if (pos != buffer.npos)//Пока не дошёл до конца буфера
          {
            for (last_position; last_position < pos; last_position++)//Копирует слово из буфера
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