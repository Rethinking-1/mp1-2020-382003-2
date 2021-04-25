#pragma once
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