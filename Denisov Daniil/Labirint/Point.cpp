#include "Point.h"


myPoint::myPoint(int n)
{
  size = n;
  x = new int[size];
  y = new int[size];

}

myPoint::myPoint()
{
  val = 1;
  size = 500;
  x = new int[size];
  y = new int[size];
  last_positionX = 1;
  last_positionY = 1;
}
