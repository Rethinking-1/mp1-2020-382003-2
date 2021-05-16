#pragma once
#include"function.h"
class find_korney//базовый класс 2
{
public:
  virtual double get_next_point(function* func) = 0;
};
//+