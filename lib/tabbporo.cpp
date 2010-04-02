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
}
		
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

//////////////////////////clase TABBNodo/////////
TABBPoro::TABBPoro()
{
		nodo=NULL;
	
}
	
TABBPoro::TABBPoro(const TABBPoro & ab)
{
	if (ab.nodo != NULL)
	{
		nodo = new TNodoABB(*ab.nodo);
	}
	else
	{
		nodo = NULL;
	}	
}

TABBPoro::~TABBPoro()
{
	if (nodo != NULL)
	{
		delete nodo;
	}
	nodo = NULL;
}

TABBPoro& 
TABBPoro::operator=(const TABBPoro &ab)
{
	if (this != &ab)
	{
		if (nodo != NULL)
		{
			delete nodo;
		}
		if (ab.nodo != NULL)
		{
			nodo = new TNodoABB(*a.nodo);
		}
		else
		{
			nodo = NULL;
		}
	}
	return *this;
}
		
bool 
TABBPoro::operator==(const TABBPoro &a) const
{
	bool ret = false;
	if (nodo == NULL && a.nodo == NULL)
	{
		ret = true;
	}
	else if (nodo != NULL && a.nodo != NULL)
	{
		if (nodo->item == a.nodo->item)
		{
			if (nodo->iz == a.nodo->iz && nodo->de == a.nodo->de)
			{
				ret = true;
			}
		}
	}
	return ret;
}
		
bool 
TABBPoro::operator!=(const TABBPoro &a) const{ return !operator==(a);};
		
bool 
TABBPoro::EsVacio() const
{
	return nodo==NULL;
}

bool 
TABBPoro::Insertar(const TPoro &poro)
{
	bool ret = false;
	if (nodo != NULL)
	{
		if (nodo->item == poro)
		{
			ret = false;
		}
		else
		{
			if (nodo->item > poro)
			{
				ret = nodo->iz.Insertar(c);
			}
			else
			{
				ret = nodo->de.Insertar(c);
			}
		}
	}
	else
	{	
		ret = true;
		nodo = new TNodoABB;
		nodo->item = poro;
	}
	return ret;
}

bool 
TABBPoro::Borrar(const TPoro& poro)
{
		TABBPoro *aux;
		bool borrado=false;
		
		if (nodo!=NULL)
		{
			if (nodo->item<poro)
			{
				nodo->iz.Borrar(poro);
			}
			else if (nodo->item>poro)
			{
				nodo->de.Borrar(poro);
			}
			else if(nodo->item==poro)
			{
				borrado=reemplazar(nodo->iz,aux);
				delete aux;
			}
		}
	return borrado;
}

bool 
TABBPoro::reemplazar(TABBPoro actual, TABBPoro aux)
{
	bool reemplazado=false;
	if (actual.nodo->de.EsVacio())
	{
		aux.nodo->item=actual.nodo->item;
		aux=actual;
		actual=actual.nodo->iz;
		reemplazado=true;
	}
	else reemplazar(actual.nodo->de,aux);
	
	return reemplazado;
}

bool 
TABBPoro::Buscar(const TPoro&) const
{
	bool encontrado=false;
	if (nodo!=NULL)
	{
		if (nodo->item<poro)
		{
			nodo->de.Buscar(poro);
		}
		else if (nodo->item>poro)
		{
			nodo->iz.Buscar(poro);
		}
		else encontrado=true;
	}
	
	return enontrado;
}

int
TABBPoro::Altura() const
{
	int h = 0;
	int aux1, aux2;
	if (nodo != NULL)
	{
		nodo1 = nodo>iz.Altura();
		nodo2 = nodo->de.Altura();
		if (nodo > nodo2)
		{
			h = 1 + nodo1;
		}
		else
		{
			h = 1 + nodo2;
		}
	}
	return h;
}

TPoro
TABBPoro::Raiz() const
{
	return this->nodo.item;
}

int
TABBPoro::Nodos() const
{
	int n = 0;
	if (nodo!= NULL)
	{
		n = 1 + nodo->iz.Nodos() + nodo->de.Nodos();
	}
	return n;
}

int 
TABBPoro::NodosHoja() const
{
	int n = 0;
	if (nodo != NULL)
	{
		if (nodo->iz.nodo == NULL && nodo->de.nodo == NULL)
		{
			n = 1;
		}
		else
		{
			n = nodo->iz.NodosHoja() + nodo->de.NodosHoja();
		}
	}
	return n;
}
