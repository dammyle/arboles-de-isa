#include <iostream>

using namespace std;

#include "tpilaporo.h"

int
main(void)
{
  TPilaPoro p;
  TPoro a(1, 2, 3, "rojo"), b(4, 5, 6, "azul");  
  TPoro c(9, 8, 7, "verde"), d(6, 5, 4, "amarillo");  

  p.Apilar(a);
  p.Apilar(b);
  p.Apilar(c);
  p.Apilar(d);

  cout << p << endl;
}
