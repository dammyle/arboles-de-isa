#include <iostream>

using namespace std;

#include "tpilaporo.h"

int
main(void)
{
  TPilaPoro p;
  TPoro a;

  if(p.EsVacia())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  p.Apilar(a);

  if(p.EsVacia())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  p.Desapilar();

  if(p.EsVacia())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  p.Apilar(a);

  if(p.EsVacia())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  p.~TPilaPoro();

  if(p.EsVacia())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;
}
