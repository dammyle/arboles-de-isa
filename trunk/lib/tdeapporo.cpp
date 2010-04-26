#include <iostream>
#include <math.h>
#include "tlistaporo.h"
#include "tdeapporo.h"
using namespace std;

/** \file tdeapporo.cpp
* \brief Procedimientos de la clase tdeapporo.
*
*/

//enum THEAP (HEAP_MINIMO, HEAP_MAXIMO);

TDeapPoro::TDeapPoro()
:v(10), posicion(2)
{}

bool TDeapPoro::Insertar(const TPoro &p)
{
     bool insertado=false;
     int i,j;
     THEAP dondeEstoy;

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
                if(dondeEstoy==HEAP_MINIMO)
                {
                        i=posicion;
                        j=ObtenerAsociadoMaximo(posicion);
                        
                        if(v[i].Volumen() > v[j].Volumen())
                        {
                                Intercambiar(i,j);
                                dondeEstoy=HEAP_MAXIMO;
                        }
                }
                else
                {
                    j=posicion;
                    i=ObtenerAsociadoMinimo(posicion);
                    if(v[i].Volumen()>v[j].Volumen())
                    {
                        dondeEstoy=HEAP_MINIMO;
                    }
                }
           }
           if(dondeEstoy==HEAP_MINIMO)
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

THEAP TDeapPoro::ObtenerHeap(int i) const
{
      int posicionEnNivel, nodosEnNivel;
      THEAP lugar;

      posicionEnNivel= i - pow (2.0, (log2(i) -1));
      nodosEnNivel= pow (2.0, log2(i));
      if(posicionEnNivel<nodosEnNivel/2)
      {
          lugar=HEAP_MINIMO;
      }
      else
      {
          lugar=HEAP_MAXIMO;
      }

      return lugar;
}

int TDeapPoro::ObtenerAsociadoMaximo(int i) const
{
    int j;

    j = i + pow(2.0,(log2(i)-1));
    if(j>posicion)
    {
        j=j/2;
    }

    return j;
}

int TDeapPoro::ObtenerAsociadoMinimo(int j) const
{
    return j-pow(2.0,(log2(j)-1));;
}

void TDeapPoro::Intercambiar(int i, int j)
{
     TPoro aux;

     aux=v[i];
     v[i]=v[j];
     v[j]=aux;
}

void TDeapPoro::FlotarMinimo(int i)
{
     while(i>2 && (v[i].Volumen() < v[i].Volumen()/2))
     {
         Intercambiar(i,i/2);
         i=i/2;
     }
}

void TDeapPoro::FlotarMaximo(int j)
{
     while(j>2 && (v[j].Volumen() < v[j].Volumen()/2))
     {
         Intercambiar(j,j/2);
         j=j/2;
     }
}

bool TDeapPoro::BorrarMin()
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
                        j=ObtenerAsociadoEnMaximo(i);
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


TVectorPoro TDeapPoro::Niveles() const
{
     int i;

     TVectorPoro vNiveles(posicion-2);
     for(i=2;i<posicion;i++)
     {
          vNiveles[i-1]=v[i];
     }

     return vNiveles;
}


TVectorPoro TDeapPoro::Inorden() const
{
     TVectorPoro v(posicion-2);
     int pos=1, i=1;

     InordenAux(v,pos,i);

     return v;
}

void TDeapPoro::InordenAux(TVectorPoro &vi, int &pos, int i) const
{
     if(i<posicion) //Estoy en el Deap
     {
          InordenAux(vi,pos,2*i);
          vi[pos]=v[i];
          pos++;
          InordenAux(vi,pos,2*i+1);
     }
}

bool TDeapPoro::Buscar(const TPoro &p)
{

}
