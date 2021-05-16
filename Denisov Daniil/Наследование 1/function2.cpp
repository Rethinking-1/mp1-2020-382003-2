#include "function2.h"

double function2::value_at_point(double point)
{
  x = point;
  func = cos(x)+x-1;
  std::cout << "Значение в точке " << x << ":   " << func << std::endl;
  return func;
}

double function2::derivative_at_point(double point)
{
  x = point;
  func = -sin(x) + 1;
  std::cout << "Производная в точке " << x << ":   " << func << std::endl;
  return func;
}

double function2::value_on_segment()
{
  int step = 1;
  int a = 0, b = 0;
  std::cout << "Введите начало отрезка:";
  std::cin >> a;
  std::cout << "Введите конец отрезка:";
  std::cin >> b;
  for (int i = a; i <= b; i = i + step)
  {
    x = i;
    func = cos(x) + x - 1;
    std::cout << "Значение функции в точке " << x << ":   " << func << std::endl;
  }
  return func;
}
//+
