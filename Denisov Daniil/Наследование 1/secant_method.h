#pragma once
#include"Find_korney.h"
#include"function.h"
#pragma once
class secant_method : public find_korney
{
  double get_next_point(function* func);//вызывает решение соответсвующей функции
};
//+