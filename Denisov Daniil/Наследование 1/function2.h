#pragma once
#include"function.h"
#include<math.h>
class function2 : public function
{
  double func;
public:
  double x = 0;
  function2(double _x)
  {
    x = _x;
    func = cos(x) + x - 1;
  }
  double value_at_point(double point)override;
  double derivative_at_point(double point)override;
  double value_on_segment(/*double point*/)override;
};
//+