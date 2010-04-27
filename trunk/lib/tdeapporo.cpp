#include <iostream>
#include <math.h>
#include "tlistaporo.h"
#include "tvectorporo.h"
#include "tdeapporo.h"
using namespace std;

/** \file tdeapporo.cpp
* \brief Procedimientos de la clase tdeapporo.
*
*/

TDeapPoro::TDeapPoro():v(10), posicion(2){}

TDeapPoro::~TDeapPoro()
{
	posicion=0;		
}

TDeapPoro&
TDeapPoro::operator=(const TDeapPoro &dp)
{
        if(this!=&dp)
        {
                v=dp.v;
                posicion=dp.posicion;
        }
        return *this;
}

TDeapPoro::TDeapPoro( const TDeapPoro &d)
{
		if (this!=&d)
		{
			posicion=d.posicion;
			
			v.TVectorPoro::operator=(d.v);
		}
}

bool
TDeapPoro::operator==(const TDeapPoro &d) 
{
	int i=0;
	bool iguales=true;
	
	if (v.Longitud()>0 && d.v.Longitud()>0 &&  v.Longitud()==d.v.Longitud())
	{
		while (i<v.Longitud() && iguales)
		{
			if (v[i]!=d.v[i])
			{
				iguales=false;
			}
			
		}
		
	}
	else
	{
		iguales=false;
	}
	
	return iguales;
}

bool 
TDeapPoro::Insertar(const TPoro &p)
{
     bool insertado=false;
     int i,j;
     THeap dondeEstoy;

     if(posicion==2)
     {
           v[posicion]=p;       //Insertamos el poro p en la posicion 2 del vector.
           posicion++;
     }
     else
     {
           if(Buscar(p)) //Si el poro p se ha encontrado.
           {
                insertado=false;
           }
           else
           {
                if(posicion==v.Longitud()+1)    //Si la posicion es la ultima del vector.
                {
                     v.Redimensionar(v.Longitud()+10);
                }
                v[posicion]=p;  //Insertamos el poro p al final del recorrido por niveles.
                dondeEstoy=ObtenerHeap(posicion);
                if(dondeEstoy==MINIMO)
                {
                        i=posicion;
                        j=ObtenerAsociadoMaximo(posicion);
                        
                        if(v[i].Volumen() > v[j].Volumen())
                        {
                                Intercambiar(i,j);
                                dondeEstoy=MAXIMO;//seguramente no haga falta, repasar luego;
                        }
                }
                else
                {
                    j=posicion;
                    i=ObtenerAsociadoMinimo(posicion);
                    if(v[i].Volumen()>v[j].Volumen())
                    {
                        dondeEstoy=MINIMO;
                    }
                }
           }
           if(dondeEstoy==MINIMO)
           {
               FlotarMinimo(i);
           }
           else
           {
               FlotarMaximo(j);
           }
           insertado=true;
           posicion++;
     }
     return insertado;
}

THeap
TDeapPoro::ObtenerHeap(int i) const
{
      int posicionEnNivel, nodosEnNivel;
      THeap lugar;

      posicionEnNivel= i - pow (2.0, (log2(i) -1));
      nodosEnNivel= pow (2.0, log2(i));
      if(posicionEnNivel<nodosEnNivel/2)
      {
          lugar=MINIMO;
      }
      else
      {
          lugar=MAXIMO;
      }

      return lugar;
}

int 
TDeapPoro::ObtenerAsociadoMaximo(int i) const
{
    int j;

    j = i + pow(2.0,(log2(i)-1));
    if(j>posicion)
    {
        j=j/2;
    }

    return j;
}

int 
TDeapPoro::ObtenerAsociadoMinimo(int j) const
{
    return j-pow(2.0,(log2(j)-1));
}

void 
TDeapPoro::Intercambiar(int i, int j)
{
     TPoro aux;

     aux=v[i];
     v[i]=v[j];
     v[j]=aux;
}

void 
TDeapPoro::FlotarMinimo(int i)
{
     while(i>2 && (v[i].Volumen() < v[i/2].Volumen()))//v[i].Volumen()/2))
     {
         Intercambiar(i,i/2);
         i=i/2;
     }
}

void 
TDeapPoro::FlotarMaximo(int j)
{
     while(j>2 && (v[j].Volumen() < v[j].Volumen()/2))
     {
         Intercambiar(j,j/2);
         j=j/2;
     }
}

bool 
TDeapPoro::BorrarMin()
{
        bool borrado;
        int i,j;

        if(posicion==2)
                borrado=false;
        else
        {
                borrado=true;
                //Paso 1, Intercambio el nodo que quiero borrar por el ultimo elemento en el recorrido por niveles.
                v[2]=v[posicion-1];
                posicion--;
                //Paso 2, hundir(intercambiar por el hijo) en heap minimo.
                i=2; // i vale 2 porque nos encontramos al principio.
                //ACLARATORIO: 2*i y 2*i+1 son los hijos.
                while((2*i < posicion && v[i].Volumen() > v[2*i].Volumen()) || (2*i+1 < posicion && v[i].Volumen() > v[2*i+1].Volumen()))
                {
                        if(2*i+1 < posicion)    //existen los 2, intercambio con el menor de los dos.
                        {
                                if(v[2*i].Volumen() < v[2*i+1].Volumen())
                                {
                                        Intercambiar(i,2*i);
                                        i=2*i;
                                }
                                else
                                {
                                        Intercambiar(i,2*i+1);
                                        i=2*i+1;
                                }
                        }
                        else    //no existen los 2.
                        {
                                Intercambiar(i,2*i);
                                i=2*i;
                        }
                        //Paso 3.
                        j=ObtenerAsociadoMaximo(i);
                        if(v[i].Volumen() > v[j].Volumen())     //Hago flotar en maximo.
                        {
                                Intercambiar(i,j);
                                while(j>3 && v[j].Volumen() > v[i].Volumen())   //j>3 porque posicion del maximo es tres.
                                {
                                        Intercambiar(j,j/2);
                                        j=j/2;
                                }
                        }
                }
        }
}


TVectorPoro 
TDeapPoro::Niveles() const
{
     int i;

     TVectorPoro vNiveles(posicion-2);
     for(i=2;i<posicion;i++)
     {
          vNiveles[i-1]=v[i];
     }

     return vNiveles;
}


TVectorPoro 
TDeapPoro::Inorden() const
{
     TVectorPoro ret(v.Longitud()-1);
     int pos=pow(2.0,(log2(v.Longitud()-1)-1));
     int i=pos;

     InordenAux(ret,pos,i);

     return ret;
}

void 
TDeapPoro::InordenAux(TVectorPoro &ret, int &pos, int i) const
{
     if(i<0) //Estoy en el Deap
     {
          InordenAux(ret,pos,2*i);
          ret[pos]=v[i];
          pos++;
          InordenAux(ret,pos,2*i+1);
     }
}

TVectorPoro 
TDeapPoro::Preorden() const
{
     TVectorPoro ret(v.Longitud()-1);//para quitar la raiz;
     int pos=1, i=1;

     PreordenAux(ret,pos,i);

     return v;
}

void 
TDeapPoro::PreordenAux(TVectorPoro &ret, int &pos, int i) const
{
     if(i<v.Longitud()) //Estoy en el Deap
     {
          PreordenAux(ret,pos,2*i);
          ret[pos]=v[i];
          pos++;
          PreordenAux(ret,pos,2*i+1);
     }
}

TVectorPoro 
TDeapPoro::Postorden() const
{
     TVectorPoro v(v.Longitud()-1);
     int pos=v.Longitud()-1;
     int i=v.Longitud();

     InordenAux(v,pos,i);

     return v;
}

void 
TDeapPoro::PostordenAux(TVectorPoro &ret, int &pos, int i) const
{
     if(i>0) //Estoy en el Deap
     {
          PreordenAux(ret,pos,i-1);
          PreordenAux(ret,pos,i-2);
          ret[pos]=v[i];
          pos--;
     }
}
bool 
TDeapPoro::Buscar(const TPoro &p)
{
	int pos=0;
	
	bool encontrado=false;
	
	while (pos<v.Longitud())
	{
		if (v[pos]==p)
		{
			encontrado=true;
		}
	}
	return encontrado;
}

