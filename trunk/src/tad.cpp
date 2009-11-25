#include <iostream>

using namespace std;

#include "tpilaporo.h"

int
main(void)
{
 /* TPilaPoro a, b, c;

  cout << "No hace nada" << endl;

//-------------------------------------->>>>>>>>>>tad2
TPilaPoro p;

 cout << p << endl;*/
//--------------------------------------->>>>>>>>>>>>>>>tad3

/*TPilaPoro p;
cout<<p<<endl;

  TPoro a(1, 2, 3, "rojo");
cout<<a<<endl;
  p.Apilar(a);

  cout << p << endl;*/
//------------------------------------->>>>>>>>>>>tad4

/* TPilaPoro p;
  TPoro a(1, 2, 3, "rojo"), b(4, 5, 6, "azul");  

  p.Apilar(a);
  p.Apilar(b);

  cout << p << endl;*/

//------------------------------------>>>>>>>>>>>>>>>>tad5
/*
  TPilaPoro p;
  TPoro a(1, 2, 3, "rojo"), b(4, 5, 6, "azul");  
  TPoro c(9, 8, 7, "verde"), d(6, 5, 4, "amarillo");  

  p.Apilar(a);
  p.Apilar(b);
  p.Apilar(c);
  p.Apilar(d);

  cout << p << endl;*/
//------------------------------------->>>>>>>>>>>>>>>tad7
  /*TPilaPoro p;
  TPoro a(1, 2, 3, "rojo");

  cout << p.Longitud() << endl;

  p.Apilar(a);

  if(a == p.Cima())
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  cout << p.Longitud() << endl;*/

//-------------------------------->>>>>>>>>>>>>>>>>>>>>>>tad8
 /* TPilaPoro p;
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

  cout << p.Cima() << endl;*/

//------------------------------------->>>>>>>>>>>>>>>>>>>>tad9
 /* TPilaPoro p;
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
    cout << "NO VACIO" << endl;*/

//----------------------------------->>>>>>>>>>>>>>>>>>>>>>ad10
 TPilaPoro p, q;
  TPoro a(1, 2, 3, "rojo");

  if(p == q)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  p.Apilar(a);

  if(p == q){
	
    cout << "SI" << endl;}
  else
    cout << "NO" << endl;


  q = p;

  if(p == q)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;



}
