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
		
TNodoABB::~TNodoABB(){}
		
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
	TVectorPoro c;
	TVectorPoro b;

	c=this->Inorden();
	b=a.Inorden();

	return c==b;
}
		
bool 
TABBPoro::EsVacio() const
{
	return nodo==NULL;
}

bool 
TABBPoro::Insertar(const TPoro &poro)
{
	TPoro etic;
	TPoro obj=poro;
	bool ret = false;
	
	if(nodo!=NULL)
	{
		etic=nodo->item;
	}
	
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

bool TABBPoro::Borrar(const TPoro &p)
{
        TNodoABB *aux;
        bool borrado;
        TABBPoro mayoriz;
        TPoro mayor;

		double pvolum=nodo->item.Volumen();
		TPoro thisvolum=p;
		
        if(nodo == NULL)        //El Poro no se encuentra en el arbol.
                borrado=false;
        else
        {
                if(thisvolum.Volumen() < pvolum)
                {
                        borrado=nodo->iz.Borrar(p);
                }
                else
                {
                    
                        if(thisvolum.Volumen() > pvolum)
                                borrado=nodo->de.Borrar(p);
                        else if(thisvolum.Volumen()==pvolum)
                        {
                                borrado=true;
                                if(nodo->iz.nodo==NULL && nodo->de.nodo==NULL)//estas en una hoja
                                {
                                        delete nodo;
                                        nodo=NULL;
                                }
                                else if(nodo->de.nodo==NULL && nodo->iz.nodo!=NULL)//tiene hijo izquierda
                                {
                                        aux=nodo;
                                        nodo=aux->iz.nodo;
                                        aux->iz.nodo=NULL;
                                        delete aux;
                                }
                                else if(nodo->de.nodo!=NULL && nodo->iz.nodo==NULL)//tiene hijo derecha
                                {
                                        aux=nodo;
                                        nodo=aux->de.nodo;
                                        aux->de.nodo=NULL;
                                        delete aux;
                                }
                                else
                                {
                                        mayor=nodo->iz.reemplazar();
                                        nodo->item=mayor;
                                        nodo->iz.Borrar(mayor);
                                }
                        }
                }
        }
        return borrado;
}

TPoro 
TABBPoro::reemplazar()const //reemplazas por el mayor de la izquierda
{
        TPoro p;
        TNodoABB *aux=NULL;

        aux=nodo;
        while(aux->de.nodo!=NULL)
        {
                aux=aux->de.nodo;
        }
        p=aux->item;
        return p;
}

bool 
TABBPoro::Buscar(const TPoro& poro) const
{
	TPoro etic;
	if (nodo!=NULL)
	{
		etic=nodo->item;
	}
	
	bool encontrado=false;
	TPoro obj=poro;
	if (nodo!=NULL)
	{
		if (etic.Volumen()<obj.Volumen())
		{
			encontrado=nodo->de.Buscar(poro);
		}
		else if (etic.Volumen()>obj.Volumen())
		{
			encontrado=nodo->iz.Buscar(poro);
		}
		else if(etic.Volumen()==obj.Volumen())
		{
			 encontrado=true;
		}
	}
	
	return encontrado;
}

TVectorPoro TABBPoro::Inorden() const
{
       int posicion = 1;
       TVectorPoro v(Nodos());
       InordenAux(v, posicion);
       return v;
}

void 
TABBPoro::InordenAux(TVectorPoro& rec, int& pos) const
{
	  if(nodo!=NULL)
      {
			nodo->iz.InordenAux(rec,pos);
			rec[pos]=nodo->item;
			pos++;
			nodo->de.InordenAux(rec,pos);
      }
}

TVectorPoro
TABBPoro::Preorden() const
{
		int pos=0;
		
		TVectorPoro ret(Nodos());
		PreordenAux(ret, pos);
		return ret;
}

void
TABBPoro::PreordenAux(TVectorPoro& ret, int& pos) const
{
		if (nodo!=NULL)
		{
			ret[pos]=nodo->item;
			pos+1;
			nodo->iz.PreordenAux(ret,pos);
			pos=pos+(nodo->iz.Nodos());
			nodo->de.PreordenAux(ret, pos);
		}	
}

TVectorPoro
TABBPoro::Postorden() const
{
		int pos=Nodos()-1;
		TVectorPoro ret(Nodos());
		PostordenAux(ret,pos);
		
		return ret;
}

void
TABBPoro::PostordenAux(TVectorPoro& ret, int& pos) const
{
	int cion=0;
	
	if(Nodos()>1)  cion=pos-nodo->iz.Nodos();
	
		if (nodo!=NULL)
		{
			nodo->iz.PostordenAux(ret, cion);
			pos-1;
			nodo->de.PostordenAux(ret, pos);
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
	TPoro aux;
	if (!this->EsVacio())
	{
		return nodo->item;
	}
	else return aux;
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
