#include <iostream>
using namespace std;

#include "tpilaporo.h"

//! \file tpilaporo.cpp
//! \brief Implementacion de la clase TPilaPoro

TPilaPoro::TPilaPoro()
{
	v.Redimensionar(10);
	posicion=0;
}

TPilaPoro::TPilaPoro(const TPilaPoro& p)
{	//vector quet tiene un puntero a datos
	v.~TVectorPoro();
	v.Redimensionar(p.Longitud());
	posicion=p.posicion;//this coge la dimension de la pila parametro.

	for (int i = 0; i <=p.Longitud() ; i++)
	{
		v[i]=p.v[i];
	}
}

TPilaPoro& 
TPilaPoro::operator=(const TPilaPoro &p)
{
cout<<"Entrando en operator="<<endl;
	if (this != &p)
	{
		if (p.Longitud()>0 )
		{
			v.Redimensionar(p.Longitud());
			posicion=p.Longitud();
			cout<<posicion<<"longitud de la parte izquierda del operando"<<endl;
			for (int i = 0; i <=p.Longitud(); i++)
			{
				v[i]=p.v[i];
			}
		}
		else if(p.EsVacia())
		{
			cout<<"ESvacia"<<endl;
			posicion=0;
			v.Redimensionar(10);
		}
		
	}
	return *this;
}

int
TPilaPoro::Longitud() const
{
	return posicion;
}

ostream&
operator<<(ostream &os, const TPilaPoro &p)
{
	os <<'{';
	int i=p.posicion-1;
	
	while (i>0)
	{
		os<<p.v[i]<<' ';
		i--;
	}
	os <<p.v[i]<<'}';
	return os;	
	
}

TPilaPoro
TPilaPoro::operator+(const TPilaPoro &p) const
{
	int i = 0;
	TPilaPoro aux;
	TPoro b;
	
	if (p.v.Longitud()>v.Longitud())
	{
		for (; i < posicion; i++)
		{
			b=v[i];
			aux.Apilar(b);
		}
		for (; i <p.posicion ; i++)
		{
			b=p.v[i];
			aux.Apilar(b);
		}
	}
	else if(v.Longitud()>p.v.Longitud())
	{
		for (; i < p.posicion; i++)
		{
			b=v[i];
			aux.Apilar(b);
		}
		for (; i <posicion ; i++)
		{
			b=p.v[i];
			aux.Apilar(b);
		}
	}
	else
	{
		aux=p;
	}

	return aux;
}

bool
TPilaPoro::Apilar(const TPoro& p) 
{
	bool exito=false;
	
	if (posicion<=10)
	{
		v[posicion]=p;
		posicion++;
		exito=true;
	}
	else
	{
		TVectorPoro a((v.Longitud()+10));
		v.~TVectorPoro();
		a[posicion]=p;	
		v=a;
		posicion++;
		exito=true;	
	}
	return exito;
}

bool
TPilaPoro::Desapilar()
{
	bool exito=false;
	TVectorPoro aux(v.Longitud()-10);
	
	for (int i = 0; i < posicion; i++)
	{
		exito=v[i].EsVacio();
	}
	
	if(!exito && v.Cantidad()==10)//en este caso crear vector con 10 posiciones menos
	{
		v.Redimensionar(v.Longitud()-10);
		posicion=posicion-10;//no se si es -9 o -10;
		v[posicion-1].~TPoro();
		exito=true;
	}
	else
	{
		v[posicion-1].~TPoro();
		posicion--;
		exito=true;
		
	}
	
	return exito;
}

TPilaPoro::~TPilaPoro()
{
	v.Redimensionar(10);	
	for (int i = 0; i < v.Longitud(); i++)
	{
		v[i].~TPoro();
	}
	
	posicion=0;
}

TPoro
TPilaPoro::Cima() const
{
	return v[posicion-1];
}

bool
TPilaPoro::operator==(const TPilaPoro& p) const
{
	bool salir=false;
	bool dist=false;	

	for (int i = 0; i <=Longitud() && i<=p.Longitud() && !salir; i++)
	{
		if (v[i]==p.v[i])
		{
			cout<<"son iguales los poros"<<endl;
			dist=false;
		}
		else
		{
			salir=true; 
			dist=true;
		}
	}
	
	return !dist;
}

bool
TPilaPoro::EsVacia() const
{
	bool vacia=false;
	
	if (posicion==0)
	{
		vacia=true;
	}
	
	
	return vacia;			
}
