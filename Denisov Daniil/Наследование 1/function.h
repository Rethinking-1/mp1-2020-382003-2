#pragma once
#include<iostream>
class function//������� ���cc
{
public:
  virtual double value_at_point(double point) = 0;
  virtual double derivative_at_point(double point) = 0;
  virtual double value_on_segment() = 0;
};
//+