#include <iostream>

using namespace std;

#include "tpilaporo.h"

int
main(void)
{
  TPilaPoro p;
  TPoro a(1, 2, 3, "rojo"), b(4, 5, 6, "azul");  

  p.Apilar(a);
  p.Apilar(b);

  cout << p << endl;
}
