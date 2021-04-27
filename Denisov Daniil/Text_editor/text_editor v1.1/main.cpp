#include"editor.h"
using namespace std;
//Сделать отношение количества ошибок к количеству букв в слове(для большей точности)
//Не записывает-считывает русскую раскладку 
int main()
{
  SetConsoleCP(866);//На случай случайного закрытия программы во время смененной кодировки
  setlocale(LC_ALL, "rus");
  std::string buffer = "В лису роделась елочк.....  В лесу она росла!.,,Ура!";//Исходное предложение
  text_editor text(buffer);
  text.Interface();
  cout << "***************Начальное предложение***************\n";
  text.Print_origin_text();
  cout << "\n***************Слова,взятые из словаря***************\n";
  text.logic(buffer);
  text.print_paragraphs();
  _getwche();
  return 0;
}