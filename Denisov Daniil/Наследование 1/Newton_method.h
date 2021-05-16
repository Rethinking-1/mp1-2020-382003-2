#pragma once
#include"Find_korney.h"
#include"function.h"
class newton_method : public find_korney
{
  double get_next_point(function*func);//вызывает решение соответсвующей функции
};
//+