#include <iostream>

using namespace std;

#include "tpilaporo.h"

void
funcion(TPilaPoro &q)
{
  cout << "funcion: " << q << endl;
}

void
otraFuncion(TPilaPoro q)
{
  cout << "otraFuncion: " << q << endl;
}

int
main(void)
{
  TPilaPoro p;
  TPoro a(1, 2, 3, "rojo");

  p.Apilar(a);
  p.Apilar(a);

  cout << p << endl;
  funcion(p);
  otraFuncion(p);
}
