#include"Solver.h"
#include"Function1.h"
#include"function2.h"

#include"Newton_method.h"
#include"secant_method.h"
//#include"function.h"
const double x = 4;
using namespace std;
int main()
{
  setlocale(LC_ALL, "rus");
  int choise = 0;
  function* f;
  find_korney* _f_k;
  cout << "Выберите функцию:\n1)2x^5+7x^3+x^2+5\n2)cos(x)+x-1:";
  cin >> choise;
  if(choise ==2)
    f = new function2(x);
 else
    f = new function1(x);
   cout << "Выберите метод решения:\n1)Метод Ньютона\n2)Метод секущих:";
   cin >> choise;
  if (choise == 2)
    _f_k = new secant_method;
  else
    _f_k = new newton_method;
  
  
 // solver solve(f,f_k);
  solver solver(f,_f_k);
  solver.solve();
  _getwche();
  return 0;
}