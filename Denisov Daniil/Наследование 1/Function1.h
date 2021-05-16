#pragma once
#include"function.h"
class function1 : public function
{
  double func;
public:
  double x = 0;
  function1(double _x)
  {
    x = _x;
    func = 2 * pow(x, 5) + 7 * pow(x, 3) + pow(x, 2) + 5;
  }
  double value_at_point(double point)override;
  double derivative_at_point(double point)override;
  double value_on_segment(/*double point*/)override;
};
//+