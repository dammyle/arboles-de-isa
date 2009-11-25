#include <iostream>

using namespace std;

#include "tpilaporo.h"

int
main(void)
{
  TPilaPoro p;
  TPoro a(1, 2, 3, "rojo");

  p.Apilar(a);

  cout << p << endl;
}
