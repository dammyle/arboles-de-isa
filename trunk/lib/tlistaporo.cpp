#include <iostream>
using namespace std;

#include "tlistaporo.h"

//! \file tlistaporo.cpp
//! \brief Implementacion de la clase TListaPoro, TListaNodo y TListaPosicion

TListaNodo::TListaNodo():anterior(NULL), siguiente(NULL){}

TListaNodo::TListaNodo(const TListaNodo &n):e(n.e), anterior(n.anterior), siguiente(n.siguiente){}

TListaNodo::~TListaNodo()
{
	siguiente=anterior=NULL;
	e.~TPoro();
}

TListaNodo&
TListaNodo::operator= (const TListaNodo &n)
{
	if (this != &n)
	{
		e = n.e;
		anterior = n.anterior;
		siguiente = n.siguiente;
	}
	return *this;
}

//======================================================================

TListaPosicion::TListaPosicion(const TListaPosicion& p)
{
	if (p.pos != NULL)
	{
		pos = p.pos;
	}
}

TListaPosicion::~TListaPosicion()
{
	pos = NULL;
}

TListaPosicion &
TListaPosicion::operator=(const TListaPosicion & p)
{
	if (this != &p)
	{
		pos = p.pos;
	}
	return *this;
}

bool 
TListaPosicion::operator==(const TListaPosicion & p) const
{
	return (p.pos->e == pos->e);
}

bool 
TListaPosicion::operator!=(const TListaPosicion & p) const
{
	return !(p.pos->e == pos->e);
}

TListaPosicion
TListaPosicion::Anterior() const
{
	TListaPosicion ret;
	ret.pos = NULL;
	if (pos != NULL && pos->anterior!= NULL)
	{
		ret.pos = pos->anterior;
	}
	return ret;
}

TListaPosicion
TListaPosicion::Siguiente() const
{
	TListaPosicion ret;
	ret.pos = NULL;
	if (pos != NULL && pos->siguiente!= NULL)
	{
		ret.pos = pos->siguiente;
	}
	return ret;
}

//======================================================================

TListaPoro::TListaPoro(const TListaPoro &l)
{
	TListaPosicion e, f;
	
	if (!l.EsVacia())
	{
		e.pos = l.primero;
		primero = new TListaNodo(*e.pos);
		f.pos = primero;
		for (e.pos = e.pos->siguiente; e.pos != NULL; e.pos = e.pos->siguiente)
		{
			f.pos->siguiente = new TListaNodo(*e.pos);
			f.pos->siguiente->anterior = f.pos;
			f.pos = f.pos->siguiente;
		}	
		ultimo = f.pos;
		e.pos = NULL;
		f.pos = NULL;
	}
}

TListaPoro::~TListaPoro()
{
	TListaPosicion e;
	
	while (primero != NULL)
	{
		e.pos = primero;
		primero = primero->siguiente;
		delete e.pos;
		e.pos = NULL;
	}
	ultimo = NULL;
}

TListaPoro& 
TListaPoro::operator=(const TListaPoro & l)
{
	TListaPosicion e, f;
	if (this != &l)
	{
		if (!this->EsVacia())
		{
			while (primero != NULL)
			{
				e.pos = primero;
				primero = primero->siguiente;
				delete e.pos;
				e.pos = NULL;
			}
			ultimo = NULL;	
		}
			if (!l.EsVacia())
			{
				e.pos = l.primero;
				primero = new TListaNodo(*e.pos);
				f.pos = primero;
				for (e.pos = e.pos->siguiente; e.pos != NULL; e.pos = e.pos->siguiente)
				{
					f.pos->siguiente = new TListaNodo(*e.pos);
					f.pos->siguiente->anterior = f.pos;
					f.pos = f.pos->siguiente;
				}	
				ultimo = f.pos;
				e.pos = NULL;
				f.pos = NULL;
			}
	}
	return *this;
}
	
bool 
TListaPoro::operator==(const TListaPoro &l) const
{
	TListaPosicion e,f;
	bool ret = true;
	
	if (l.primero != NULL && primero != NULL)
	{
		for (e.pos = l.primero, f.pos = primero; e.pos != l.ultimo && f.pos != ultimo;
			e.pos = e.pos->siguiente, f.pos = f.pos->siguiente)
			{
				if (!(e.pos->e == f.pos->e))
				{
					ret = false;
				}
			}
			if (ultimo->e != l.ultimo->e)
			{
				ret = false;
			}
	}
	else if(l.primero == NULL && primero == NULL)
	{
		ret = true;
	}
	else ret = false;
	return ret;
}

bool
TListaPoro::operator!=(const TListaPoro &l) const
{
	return !operator==(l);
}

TListaPoro
TListaPoro::operator+(const TListaPoro &l) const
{
	TListaPoro ret(*this);
	TListaPosicion e;
	
	if (!l.EsVacia())
	{
		for (e.pos = l.primero; e.pos != NULL; e.pos = e.pos->siguiente)
		{
			ret.ultimo->siguiente = new TListaNodo(*e.pos);
			ret.ultimo->siguiente->anterior = ret.ultimo;
			ret.ultimo = ret.ultimo->siguiente;
		}
	}
	return ret;
}

TListaPoro
TListaPoro::operator-(const TListaPoro &l) const
{
	TListaPosicion e, f;
	TListaNodo aux;
	TListaPoro ret;
	f.pos = NULL;
	
	if (!l.EsVacia())
	{
		for (e.pos = primero; e.pos != NULL; e.pos = e.pos->siguiente)
		{
			if (!l.Buscar(e.pos->e))
			{
				aux.e = e.pos->e;
				if (ret.primero == NULL)
				{
					ret.primero = new TListaNodo(aux);
					ret.primero->siguiente = NULL;
					ret.primero->anterior = NULL;
					f.pos = ret.primero;
				}
				else
				{
					f.pos->siguiente = new TListaNodo(aux);
					f.pos->siguiente->anterior = f.pos;
					f.pos = f.pos->siguiente;
				}
			}
		}
		ret.ultimo = f.pos;
	}
	else
	{
		ret = (*this);
	}
	
	return ret;
}

bool
TListaPoro::EsVacia() const
{
	return (this->primero == NULL);
}		

bool 
TListaPoro::Borrar(const TPoro &c)
{
	bool ret = false;
	TListaPosicion e;
	e.pos = primero;
	while(!ret && e.pos != NULL)
	{
		if (e.pos->e == c)
		{
			ret = true;
			if(Longitud()==1)
			{
				primero=ultimo=NULL;	
			}
			else if (e.pos->anterior == NULL)
			{
				primero = primero->siguiente;
				primero->anterior = NULL;
			}
			else if (e.pos->siguiente == NULL)
			{
				ultimo = ultimo->anterior;
				ultimo->siguiente = NULL;
			}
			else
			{
				e.pos->anterior->siguiente = e.pos->siguiente;
				e.pos->siguiente->anterior = e.pos->anterior;
			}
			e.pos->anterior = NULL;
			e.pos->siguiente = NULL;
			delete e.pos;
		}
		else
		{
			e.pos = e.pos->siguiente;
		}
	}
	e.pos = NULL;
	return ret;
}

bool
TListaPoro::Borrar(const TListaPosicion &e)
{
	bool ret = false;
	
	if (PerteneceALista(e))
	{
		ret = true;
		if (e.pos->anterior == NULL)
		{
			primero = primero->siguiente;
			if (primero != NULL)
			{
				primero->anterior = NULL;
			}
		}
		else if (e.pos->siguiente == NULL)
		{
			ultimo = ultimo->anterior;
			if (ultimo != NULL)
			{
				ultimo->siguiente = NULL;
			}
		}
		else
		{
			e.pos->anterior->siguiente = e.pos->siguiente;
			e.pos->siguiente->anterior = e.pos->anterior;
		}
		e.pos->anterior = NULL;
		e.pos->siguiente = NULL;
		delete e.pos;
	}
	return ret;
}

TPoro
TListaPoro::Obtener(const TListaPosicion &p) const
{
	TPoro ret;
	TListaPosicion aux=Primera();
	
	if (p.pos != NULL && PerteneceALista(p))
	{
		while (aux.pos != NULL)
		{
			if (aux.pos->e == p.pos->e)
			{
				ret = p.pos->e;
			}
			aux.pos = aux.pos->siguiente;
		}
	}
	return ret;
}
		
bool
TListaPoro::Buscar(const TPoro &c) const
{
	bool ret = false;
	TListaPosicion e;
	e.pos = primero;
	while(!ret && e.pos != NULL)
	{
		if (e.pos->e == c)
		{
			ret = true;
		}
		else
		{
			e.pos = e.pos->siguiente;
		}
	}
	e.pos = NULL;
	return ret;
}		
		
int
TListaPoro::Longitud() const
{
	TListaPosicion e;
	int ret = 0;
	e.pos = primero;
	while (e.pos != NULL)
	{
		ret++;
		e.pos = e.pos->siguiente;
	}
	return ret;
}

TListaPosicion 
TListaPoro::Primera() const
{
	TListaPosicion ret;
	ret.pos = primero;
	return ret;
}

TListaPosicion
TListaPoro::Ultima() const
{
	TListaPosicion ret;
	ret.pos = ultimo;
	return ret;
}

bool 
TListaPoro::Insertar(const TPoro& p)
{
	bool insertado=false;
	bool yata=Buscar(p);
	TPoro aux=p;
	TListaPosicion n;
	TListaNodo nuevo;
	nuevo.e=p;
	n.pos=primero;

	while (!n.EsVacia() && !insertado && !yata)
	{
		if (n.pos->e.Volumen()>aux.Volumen())
		{
			insertado=true;
		}
		else 
		{
			n.pos=n.pos->siguiente;	
		}
	}
	if (EsVacia())
	{
		ultimo=primero=new TListaNodo(nuevo);
	}
	else if(insertado && !yata)
	{
		TListaPosicion aux;
		aux.pos=n.pos->anterior;
	
		n.pos->anterior=new TListaNodo(nuevo);
		n.pos->anterior->anterior=aux.pos;
		aux.pos->siguiente=n.pos->anterior;
	}
	else if(!yata && aux.Volumen()>ultimo->e.Volumen())
	{
		ultimo->siguiente=new TListaNodo(nuevo);
		ultimo->siguiente->anterior=ultimo;
		ultimo=ultimo->siguiente;
	}
	return insertado;	
}

ostream&
operator<<(ostream & os, const TListaPoro &l)
{
	TListaPosicion e;
	e=l.Primera();
	int i=0;
	int longi=l.Longitud();
	bool espacio = false;
	os <<'(';
	if (l.primero != NULL)
	{
		for (; i<longi; e = e.Siguiente())
		{
			if (espacio)
			{
				os <<' ';
			}
			os << l.Obtener(e);//mirar esto
			espacio = true;
			i++;
		}		
	}
	os <<')';
	return os;
}

bool
TListaPoro::PerteneceALista(const TListaPosicion &p) const
{
	TListaPosicion aux;
	aux.pos = primero;
	bool ret = false;
	if (p.pos != NULL)
	{
		while (!ret && aux.pos != NULL)
		{
			if (aux.pos == p.pos)
			{
				ret = true;
			}
			aux.pos = aux.pos->siguiente;
		}
	}
	return ret;
}
