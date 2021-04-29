#include"editor.h"
using namespace std;
int main()
{
  SetConsoleCP(866);//На случай случайного закрытия программы во время смененной кодировки
  setlocale(LC_ALL, "rus");
  std::string buffer = "добрий вечир. Я вчира кушола тортек. Пака.";//Исходное предложение
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