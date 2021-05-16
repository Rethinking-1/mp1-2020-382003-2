#include"Function1.h"
double function1::value_at_point(double point)
{
  x = point;
  func = 2 * pow(x, 5) + 7 * pow(x, 3) + pow(x, 2) + 5;
  std::cout << "«начение в точке " << x << ":   " << func<<std::endl;
  return func;
}
double function1::derivative_at_point(double point)
{
  x = point;
  func = 10.0 * pow(x, 4) + 21.0 *pow(x,2) + 2*x;
  std::cout << "«начение производной в точке "<< x<<":   "<< func << std::endl;
  return func;
}
double function1::value_on_segment(/*double point*/)
{
  int step = 1;
  int a = 0, b = 0;
  std::cout << "¬ведите начало отрезка:";
  std::cin >> a;
  std::cout << "¬ведите конец отрезка:";
  std::cin >> b;
  for (int i = a; i <= b; i = i + step)
  {
    x = i;
    func = 2 * pow(x, 5) + 7 * pow(x, 3) + pow(x, 2) + 5;
    std::cout << "значение в точке " << x << ":   " << func<<std::endl;
  }
  return func;
}
//+