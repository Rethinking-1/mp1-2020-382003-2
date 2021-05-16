#pragma once
#include"Find_korney.h"
class solver
{
public:
  find_korney* f_k;
  function* func;
  solver(function *_func, find_korney *_f_k)
  {
    f_k = _f_k;
    func = _func;
  }
  void solve();
};
//+