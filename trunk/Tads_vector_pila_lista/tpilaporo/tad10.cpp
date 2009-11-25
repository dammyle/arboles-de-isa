#include <iostream>

using namespace std;

#include "tpilaporo.h"

int
main(void)
{
  TPilaPoro p, q;
  TPoro a(1, 2, 3, "rojo");

  if(p == q)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  p.Apilar(a);

  if(p == q)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  q = p;

  if(p == q)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
}
