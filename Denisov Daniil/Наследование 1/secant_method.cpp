#include "secant_method.h"
#include <math.h>
#define epsilon 0.0001 //Требуемая точность вычисления корня
double secant_method::get_next_point(function* func)
{
  double answer;
  double x0 = 5, x1 = 6;
  double f_x0,f_x1;
  while (fabs(x1-x0) > epsilon)
  {
    f_x0 = func->value_at_point(x0);
    f_x1 = func->value_at_point(x1);
    answer = x1 - (x1 - x0) / (f_x1 - f_x0) * f_x1;

    x0 = x1;
    x1 = answer;

   /* f_xk = func->value_at_point(x1);
    back_x = back_x / (df - f_xk) * f_xk;
    df = f_xk;
    x1 = x1 + back_x;*/
   /* f_back_x = func->derivative_at_point(x0);
    x0 = xk - (xk - x0) * f_xk / (f_xk - f_back_x);
    xk = xk - (xk - x0) * f_xk / (f_xk - f_back_x);*/


    std::cout << "temp secant method:\n" << answer<<std::endl;
    _getwche();
  }
  std::cout << "answer:" << answer;
  return x0;
}
//+Верно работает