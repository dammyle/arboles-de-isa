#include <iostream>
using namespace std;

#include "tlistaporo.h"
/////////////////////////clase TNodoABB inicio //////
TNodoABB::TNodoABB()
{
	TPoro a;
	
	item=a;
	
	iz=de=NULL;
}
		
TNodoABB::TNodoABB(const TNodoABB& b)
{
	item=b.item;
	iz=b.iz;
	de=b.de;
}
		
TNodoABB::~TNodoABB()
{
		item=0;
		iz=de=NULL;
}
		//! \brief Operador = 
		/*!	Asigna T234Nodo*/
TNodoABB::TNodoABB& operator=(const TNodoABB& ab)
{
	if (this!=ab)
	{
		item=ab.item;
		de=ab.de;
		iz=ab.iz;
	}
return *this;	
}
		
bool operator==(const TNodoABB& ab) const
{
	bool ret=false;
	
		if (item==ab.item && iz==ab.iz && de==ab.de)
		{
			ret=true;
		}
		
	return ret;
}
///////////////////////////fin TNodoABB /////////

TABBPoro::TABBPoro()
{
		nodo=NULL;
	
}
	
TABBPoro::TABBPoro(const TABBPoro & ab)
{
		nodo=ab->nodo;	
}
		//! \brief Destructor de TA234Com
		/*!	Libera la memoria ocupada del árbol AVL*/
TABBPoro::~TABBPoro()
{
		nodo=NULL;
}
		//! \brief Operador =
		/*!	Asigna un árbol 234 a otro*/
TABBPoro::TABBPoro& operator=(const TABBPoro & ab)
{
	if (this!=NULL)
	{
		nodo=ab->nodo;
	}
	
	
}
		//! \brief Operador ==
		/*!	Devuelve verdadero si ambos árboles son iguales*/
		bool operator==(const TABBPoro &) const;
		//! \brief Operador != 
		/*!	Devuelve verdadero si los árboles son distintos*/
		bool operator!=(const TABBPoro &a) const{ return !operator==(a);};
		//! \brief EsVacio
		/*!	Devuelve true si el árbol 234 está vacio*/
		bool EsVacio() const ;
