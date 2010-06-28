#include <iostream>
#include "tcolaabbporo.h"

using namespace std;

int
main(void)
{
/********************************************/
/***************** ENCOLAR NULL, ARBOL VACIO*/
/********************************************/
  
  TColaABBPoro c;
  TABBPoro a;

  c.Encolar(NULL);
  c.Encolar(&a);

  cout<<c<<endl;

  return 1; 

}
