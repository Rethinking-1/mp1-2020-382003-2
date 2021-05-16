#include "Newton_method.h"
#include <math.h>
#define epsilon 0.0000001 //Требуемая точность вычисления корня
double newton_method::get_next_point(function* func)
{
  double xk = 5;
  double next_x = 5;
  do
  {
    xk = next_x;
    next_x = xk - (func->value_at_point(xk) / func->derivative_at_point(xk));
    std::cout << "temp Newton method:" << next_x << std::endl;
  } while (fabs(next_x - xk) > epsilon);
  std::cout << "Корень:" << next_x;
  return next_x;
}
//+Верно работает
