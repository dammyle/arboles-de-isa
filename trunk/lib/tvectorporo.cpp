#include <iostream>
using namespace std;

#include "tvectorporo.h"
#include <math.h>

//! \file tvectorporo.cpp
//! \brief Implementacion de la clase TVectorPoro

TVectorPoro::TVectorPoro()
{
	dimension=0;
	datos=NULL;
		
}
TVectorPoro::TVectorPoro(const int tam)
{
	if (tam < 0)
	{
		datos = NULL;
		dimension = 0;
	}
	else
	{
		dimension = tam;
		datos= new TPoro[tam];	
	}
}

TVectorPoro::TVectorPoro(const TVectorPoro &t)
{
	int i;
	this->dimension = t.dimension;
	
	this->datos = new TPoro[t.dimension];
	
	for (i = 0; i < t.dimension; i++)
	{
		this->datos[i] = t.datos[i];
	}
}

TVectorPoro::~TVectorPoro()
{
	dimension = 0;
	delete[] datos;	
}

TVectorPoro&
TVectorPoro::operator=(const TVectorPoro &t)
{
	if (this != &t)
	{
		delete[] this->datos;
		int i;
		this->dimension = t.dimension ;
		
		this->datos = new TPoro[t.dimension ];
		
		for (i = 0; i < t.dimension ; i++)
		{
			this->datos[i] = t.datos[i];
		}
	}
	return *this;
}

bool
TVectorPoro::operator== (const TVectorPoro &t) const
{
	bool ret = dimension == t.dimension;
	
	for (int i = 0 ;ret && i < t.dimension; i++)
	{
		ret = ((t.datos[i]) == (this->datos[i]));
	}
	
	return ret;
}

bool 
TVectorPoro::operator!= (const TVectorPoro &t) const
{
	return !(*this==t);
}

TPoro&
TVectorPoro::operator[](const int pos)
{
	TPoro *ret = NULL;
	if (pos-1 < dimension && pos-1 >= 0)
	{
		ret = &datos[pos-1];
	}
	else
	{
		ret = &error;
	}
	return *ret;
}

TPoro
TVectorPoro::operator[](const int pos) const
{
	TPoro ret;
	if (pos-1 < dimension && pos-1 >= 0)
	{
		ret = datos[pos-1];
	}
	else
	{
		ret = error;
	}
	return ret;	
}

int
TVectorPoro::Longitud() const
{
	return dimension;
}

int
TVectorPoro::Cantidad() const
{
	int ret = 0;
	for (int i = 0; i < dimension; i++)
	{
		if (!datos[i].EsVacio())
			ret++;
	}
	return ret;
}


bool
TVectorPoro::Redimensionar(const int tam) 
{
	bool ret = false;
	TVectorPoro *aux;
	
	if (tam > 0 && tam != dimension)
	{
		aux = new TVectorPoro(*this);
		dimension = tam;
		delete[] datos;
		datos = new TPoro[tam];
		for (int i = 0; i < aux->dimension && i < dimension; i++)//en cuanto llegue a la menor dimension de los dos para.
		{
			datos[i] = aux->datos[i];
		}
		ret = true;
		delete aux;
	}
	return ret;
}

ostream &
operator <<(ostream &os, const TVectorPoro &t)
{
	os <<"[";
	for (int i = 0; i < t.dimension; i++)
	{
		os<<i+1<<" "<<t.datos[i]<<" ";
	}
	os <<"]";	
	return os;
}


