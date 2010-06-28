#include <iostream>
using namespace std;

#include "tvectorporo.h"
#include "tporo.h"
#include "tabbporo.h"
#include "tcolaabbporo.h"

TColaABBPoro::TColaABBPoro(const TColaABBPoro &c)
{
	TECAP* aux=c.primero;
	if (c.primero==NULL)
	{
		primero=ultimo=NULL;
	}
	else
	{
		ultimo=primero=new TECAP(*aux);
		aux=aux->sig;
		while (aux!=NULL)
		{
			ultimo->sig=new TECAP(*aux);
			ultimo=ultimo->sig;
			aux=aux->sig;
		}		
	}
}

TColaABBPoro&
TColaABBPoro::operator=(const TColaABBPoro& c)
{
	TECAP* aux=c.primero;
	if (this!=&c)
	{
		if (c.primero==NULL)
		{
			primero=ultimo=NULL;
		}
		else
		{
			ultimo=primero=new TECAP(*aux);
			aux=aux->sig;
			while (aux!=NULL)
			{
				ultimo->sig=new TECAP(*aux);
				ultimo=ultimo->sig;
				aux=aux->sig;
			}		
		}
	}
	return *this;
}

TColaABBPoro::~TColaABBPoro()
{
	TECAP* aux=primero;
	if (aux==NULL)
	{
		ultimo=primero=NULL;
	}
	else
	{
		while (aux!=ultimo->sig)
		{
			primero=primero->sig;
			delete(aux);
			aux=primero;	
		}	
	}
}
	
bool
TColaABBPoro::Encolar(TABBPoro* a)
{
	bool ret=false;
	if (ultimo!=NULL)
	{
		ultimo->sig=new TECAP();
		ultimo->sig->arbol=a;
		ultimo=ultimo->sig;
		ret=true;
	}	
	else
	{
		ultimo=primero=new TECAP();
		primero->arbol=a;
		ret=true;
	}
	
	return ret;
}
	
TABBPoro*
TColaABBPoro::Cabeza() const
{
	TABBPoro* aux= NULL;
	if (primero!= NULL)
	{
		aux=primero->arbol;
	}
	return aux;	
}

bool 
TColaABBPoro::Desencolar()
{
	TECAP* aux=primero;
	bool ret=false;
	if (primero!=NULL)
	{
		primero=primero->sig;
		delete(aux);
		ret=true;
		
		if (primero==NULL)
		{
			ultimo=NULL;
		}
		
	}

	return ret;
}

int
TColaABBPoro::Longitud() const
{
	int i=0;
	TECAP* aux=primero;
	while (aux!=NULL)
	{
		i++;
		aux=aux->sig;
	}
	return i;
}

bool TColaABBPoro::EsVacia()
{
    bool ret=false;
    if(primero==NULL && ultimo==NULL)
    {
        ret=true;
    }

    return ret;
}

ostream& 
operator<<(ostream &os,const TColaABBPoro& cola)
{

    TColaABBPoro p(cola);
    os << '(';
    while(!p.EsVacia())
    {
        if(p.Cabeza()!=NULL)
        {
            os << p.Cabeza()->Raiz();
        }
        else
        {
            os << ".";
        }
        if(p.primero!=p.ultimo)
        {
            os << " ";
        }
        p.Desencolar();
    }
    os << ')';

    return os;
}

//////////////////////nodo de la cola///////////////////
TECAP::TECAP(const TECAP& n)
{
	arbol=n.arbol;
	sig=NULL;
}

TECAP::~TECAP()
{
	arbol=NULL;
	sig=NULL;	
}

TECAP& 
TECAP::operator=(const TECAP & n)
{
		if (this!=&n)
		{
			arbol=n.arbol;
			sig=n.sig;
		}
}

