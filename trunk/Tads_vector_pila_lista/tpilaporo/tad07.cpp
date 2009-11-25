#include <iostream>

using namespace std;

#include "tpilaporo.h"

int
main(void)
{
  TPilaPoro p;
  TPoro a(1, 2, 3, "rojo");

  cout << p.Longitud() << endl;

  p.Apilar(a);

  if(a == p.Cima())
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  cout << p.Longitud() << endl;
}
