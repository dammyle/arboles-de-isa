#include <iostream>
#include "tdeapporo.h"
using namespace std;

int
main(void)
{
/****************************************************/
/***************** CONSTRUCTOR DE COPIA, "=", "==" */
/***************************************************/
  TDeapPoro a,c;

  TPoro p1(1,2,3,"rojo");
  a.Insertar(p1);

  TDeapPoro b(a);
  c=b;
  
  cout<<"por aqui"<<endl;

  if ( a==b )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  if ( c==b )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  return 1;
}
