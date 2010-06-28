#include <iostream>
#include "tdeapporo.h"
using namespace std;

int
main(void)
{
  TDeapPoro a,b;

  TPoro p1(1,2,3,"aaaa");
  TPoro p2(1,2,3,"bbbb");
  TPoro p3(2,1,3,"bbbb");
  TPoro p4(10,1,5, "bbbb");
  TPoro p5(20,1,6, "bbbb");
  TPoro p6(10,2,7, "bbbb");
  TPoro p7(10,3,8, "bbbb");
  TPoro p8(10,4,9, "bbbb");
  TPoro p9(10,4,10, "bbbb");
  TPoro p10(10,4,1, "bbbb");
  TPoro p11(10,4,4, "bbbb");
  TPoro p12(10,4,2, "bbbb");
  TPoro p13(2,1,3,"bbbc");

  b.Insertar(p2);
  b.Insertar(p1);
  b.Insertar(p13);
  b.Insertar(p8);
  b.Insertar(p6);
  b.Insertar(p5);
  b.Insertar(p7);
  b.Insertar(p4);
  b.Insertar(p9);
  b.Insertar(p10);
  b.Insertar(p11);
  b.Insertar(p12);

  a.Insertar(p12);

  a.BorrarMax();
  if (a.EsVacio())
    cout<<"VACIO"<<endl;

  a.Insertar(p10);
  a.BorrarMin();
  if (a.EsVacio())
    cout<<"VACIO"<<endl;
  
  a.Insertar(p10);
  a.Insertar(p11);
  a.BorrarMax();
  a.BorrarMin();

  if (a.EsVacio())
    cout<<"VACIO"<<endl;

  while (!b.EsVacio())
  b.BorrarMax();
  
  if (b.EsVacio())
    cout<<"VACIO"<<endl;
  
  return 1;
}
