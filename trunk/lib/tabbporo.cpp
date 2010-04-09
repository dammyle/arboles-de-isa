#include <iostream>
using namespace std;

#include "tvectorporo.h"
#include "tporo.h"
#include "tabbporo.h"

/////////////////////////clase TNodoABB inicio //////
		
TNodoABB::TNodoABB(const TNodoABB& b)
{
	item=b.item;
	iz=b.iz;
	de=b.de;
}
		
TNodoABB::~TNodoABB()
{
	item=0;
}
		
TNodoABB&
TNodoABB::operator=(const TNodoABB& ab)
{
	if (this!=&ab)
	{
		item=ab.item;
		de=ab.de;
		iz=ab.iz;
	}
return *this;	
}
		
bool 
TNodoABB::operator==(const TNodoABB& ab) const
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
			nodo = new TNodoABB(*ab.nodo);
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
TABBPoro::EsVacio() const
{
	return nodo==NULL;
}

bool 
TABBPoro::Insertar(const TPoro &poro)
{
	TPoro etic=nodo->item;
	TPoro obj=poro;
	bool ret = false;
	if (nodo != NULL)
	{
		if (etic.Volumen() == obj.Volumen())
		{
			ret = false;
		}
		else
		{
			if (etic.Volumen()> obj.Volumen())
			{
				ret = nodo->iz.Insertar(poro);
			}
			else
			{
				ret = nodo->de.Insertar(poro);
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
		TPoro etic=nodo->item;
		TPoro obj=poro;
		
		if (nodo!=NULL)
		{
			if (etic.Volumen()<obj.Volumen())
			{
				nodo->iz.Borrar(poro);
			}
			else if (etic.Volumen()>obj.Volumen())
			{
				nodo->de.Borrar(poro);
			}
			else if(etic.Volumen()==obj.Volumen())
			{
				borrado=reemplazar(nodo->iz,*aux);
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
TABBPoro::Buscar(const TPoro& poro) const
{
	TPoro etic=nodo->item;
	bool encontrado=false;
	TPoro obj=poro;
	if (nodo!=NULL)
	{
		if (etic.Volumen()<obj.Volumen())
		{
			nodo->de.Buscar(poro);
		}
		else if (etic.Volumen()>obj.Volumen())
		{
			nodo->iz.Buscar(poro);
		}
		else encontrado=true;
	}
	
	return encontrado;
}

TVectorPoro 
TABBPoro::Inorden() const
{
	int pos=1;
	
	TVectorPoro ret(Nodos());
	
	InordenAux(ret,pos);
	
	return ret;
}

void 
TABBPoro::InordenAux(TVectorPoro& rec, int pos) const
{
	if (nodo!= NULL)
	{
		nodo->iz.InordenAux(rec,pos+1);
		rec[pos]=nodo->item;
		nodo->de.InordenAux(rec,pos+1);
	}
}

TVectorPoro
TABBPoro::Preorden() const
{
		int pos=1;
		
		TVectorPoro ret(Nodos());
		PreordenAux(ret, pos);
		return ret;
}

void
TABBPoro::PreordenAux(TVectorPoro& ret, int pos) const
{
		if (nodo!=NULL)
		{
			ret[pos]=nodo->item;
			nodo->iz.PreordenAux(ret,pos+1);
			nodo->de.PreordenAux(ret, pos+1);
		}	
}

TVectorPoro
TABBPoro::Postorden() const
{
		int pos=1;
		TVectorPoro ret(Nodos());
		PostordenAux(ret,pos);
		
		return ret;
}

void
TABBPoro::PostordenAux(TVectorPoro& ret, int pos) const
{
		if (nodo!=NULL)
		{
			nodo->iz.PostordenAux(ret, pos+1);
			nodo->de.PostordenAux(ret, pos+1);
			ret[pos]=nodo->item;
		}
}

TVectorPoro 
TABBPoro::Niveles() const
{
	TVectorPoro ret;
	TColaABBPoro c;
	TABBPoro *aux;
	c.Encolar((TABBPoro*)this);
	int i=0;
	while (!c.EsVacia())
	{
		aux = c.Cabeza();
		c.Desencolar();
		if (aux != NULL && aux->nodo != NULL)
		{
			ret[i]=aux->nodo->item;

			if (aux->nodo->iz.nodo != NULL)
			{
				c.Encolar(&aux->nodo->iz);
			}
			if (aux->nodo->de.nodo != NULL)
			{
				c.Encolar(&aux->nodo->de);
			}
		}
		i++;
	}
	return ret;
}


int
TABBPoro::Altura() const
{
	int h = 0;
	int nodo1, nodo2;
	if (nodo != NULL)
	{
		nodo1 = nodo->iz.Altura();
		nodo2 = nodo->de.Altura();
		if (nodo1 > nodo2)
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
	return nodo->item;
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


TABBPoro
TABBPoro::operator+(TABBPoro& de) const
{
	TABBPoro *iz=new TABBPoro(*this);
	
	TVectorPoro opde(de.Niveles());
	
	int i=0;
	
	while(i< opde.Longitud())
	{
			iz->Insertar(opde[i]);
	}
	return *iz;
}

TABBPoro
TABBPoro::operator-(TABBPoro& de) const//mirar que esto no sabemos muy  bien como funciona
{
	TABBPoro *iz=new TABBPoro(*this);
	
	TVectorPoro opde(de.Niveles());
	
	int i=0;
	
	while(i< opde.Longitud())
	{
			iz->Insertar(opde[i]);
	}
	return *iz;
}
