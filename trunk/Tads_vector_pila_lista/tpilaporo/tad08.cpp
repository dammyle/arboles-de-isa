#include <iostream>

using namespace std;

#include "tpilaporo.h"

int
main(void)
{
  TPilaPoro p;
  TPoro a, b(1, 2, 3), c(4, 5, 6, "rojo");

  p.Apilar(c);
  p.Apilar(b);
  p.Apilar(a);

  cout << p.Cima() << endl;
  p.Desapilar();

  cout << p.Cima() << endl;
  p.Desapilar();

  cout << p.Cima() << endl;
  p.Desapilar();

  cout << p.Cima() << endl;
}
