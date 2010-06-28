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
TDeapPoro::TDeapPoro():v(10)
{
		posicion=2;
}

TDeapPoro::TDeapPoro(const TDeapPoro &dp)
{
		v=dp.v;
		posicion=dp.posicion;
}

TDeapPoro::~TDeapPoro()
{
        posicion=2;
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

bool 
TDeapPoro::operator==(const TDeapPoro &dp) const
{
        bool iguales=true;
        int i=0;

        while(i<posicion && i<dp.posicion && iguales) //Comprobar que las 2 posiciones son iguales.
        {
                if(v[i]!=dp.v[i])
                {
                        iguales=false;
                }
                else
                        i++;
        }
        
        return iguales;
}

bool 
TDeapPoro::Insertar(const TPoro &p)
{
     bool insertado=false;
     int i,j;
     bool actual;
     bool salir=false;

     if(posicion==2)
     {
           v[posicion]=p;       //Insertamos el poro p en la posicion 2 del vector.
           posicion++;
           insertado=true;
     }
     else
     {
           if(Buscar(p)) //Si el poro p se ha encontrado.
           {
			   cout<<"dentro de la funcion buscar"<<endl;
                insertado=false;
                salir=true;
           }
           else if(!salir)
           {
                if(posicion==v.Longitud()+1)    //Si la posicion es la ultima del vector.
                {
                     v.Redimensionar(v.Longitud()+10);
                }
                v[posicion]=p;  //Insertamos el poro p al final del recorrido por niveles.
                actual=ObtenerHeap(posicion);
                if(actual==false)
                {
                        i=posicion;
                        j=ObtenerAsociadoMaximo(posicion);
                        if(v[i].Volumen() > v[j].Volumen())
                        {
                                Intercambiar(i,j);
                                actual=true;
                        }
                }
                else
                {
                    j=posicion;
                    i=ObtenerAsociadoMinimo(posicion);
                    if(v[i].Volumen()>v[j].Volumen())
                    {
                        actual=false;
                        Intercambiar(i,j);
                        
                    }
                }
                         insertado=true;
                         posicion++;
           }
           if(actual==false && !salir)
           {
               FlotarMin(i);
           }
           else if(!salir)
           {
               FlotarMax(j);
           }
     }
     return insertado;
}

bool
TDeapPoro::ObtenerHeap(int i) const
{
      int posicionEnNivel, nodosEnNivel;
      bool lugar;

      int prueba=0,j=0;

      j=i;
      while(j>=2)
      {
          j=j/2;
          prueba++;
      }

      nodosEnNivel = pow (2.0, prueba);
      posicionEnNivel = i - nodosEnNivel;
      
      if(posicionEnNivel<nodosEnNivel/2)
      {
          lugar=false;//en heap minimo
      }
      else
      {
          lugar=true;//en heap maximo
      }

      return lugar;
}

int 
TDeapPoro::ObtenerAsociadoMaximo(int i) const
{
    int j;

    j = i + pow(2.0,((int)log2(i)-1));
    
    if(j>=posicion)
    {
        j=j/2;
    }

    return j;
}

int 
TDeapPoro::ObtenerAsociadoMinimo(int j) const
{
    int prueba=0,i=0,nodosEnNivel=0;
    i=j;
      while(i>=2)
      {
          i=i/2;
          prueba++;
      }
    nodosEnNivel = pow (2.0, prueba);

    j=j-(nodosEnNivel/2);

    return j;
    //return j-pow(2.0,(log2(j-1)));
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
TDeapPoro::FlotarMin(int i)
{
     while(i>2 && (v[i].Volumen() < v[i/2].Volumen()))
     {
         Intercambiar(i,i/2);
         i=i/2;
     }
}

void 
TDeapPoro::FlotarMax(int j)
{
     while(j>3 && (v[j].Volumen() > v[j/2].Volumen()))
     {
         Intercambiar(j,j/2);
         j=j/2;
     }
}

bool 
TDeapPoro::BorrarMax()
{
        bool borrado;
        int i,j;
        
        if(posicion<=2)
                borrado=false;
        else
        {
                borrado=true;
                //Paso 1, Intercambio el nodo que quiero borrar por el ultimo elemento en el recorrido por niveles.
                //cout << posicion << endl;
                v[3]=v[posicion-1];
                posicion--;
                //cout << i << endl;
                j=3;
                //Paso 2, hundir(intercambiar por el hijo) en heap minimo.
                //ACLARATORIO: 2*i y 2*i+1 son los hijos.
                while((2*j < posicion && v[j].Volumen() < v[2*j].Volumen()) || (2*j+1 < posicion && v[j].Volumen() < v[2*j+1].Volumen()))
                {
                        //i=ObtenerAsociadoMinimo(j);
                       // if(2*i+1 < posicion)    //existen los 2, intercambio con el menor de los dos.
                    if(2*j+1 < posicion)
                        {
                               // if(v[j].Volumen()< v[i].Volumen() || v[j].Volumen()<v[2*i].Volumen() || v[j].Volumen()<v[2*i+1].Volumen())
                                //{
                                        if(v[2*j].Volumen()>v[2*j+1].Volumen())
                                        {
                                                Intercambiar(j,2*j);
                                                //FlotarMin(2*i);
                                                j=2*j;
                                        }
                                        else
                                        {
                                                Intercambiar(j,2*j+1);
                                                //FlotarMin(2*i*1);
                                                j=2*j+1;
                                        }
                                 //}
                        }
                        else    //no existen los 2.
                        {
                                Intercambiar(j,2*j);
                                j=2*j;
                        }
                        //Paso 3.
                        //j=ObtenerAsociadoMaximo(i);
                        i=ObtenerAsociadoMinimo(j);
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
        TVectorPoro aux(posicion-1);

        for(i=0;i<posicion;i++)
        {
            aux[i]=v[i];
        }
        v=aux;

        int lol=0;
        for(int prueba=2;prueba<posicion;prueba++)
        {
            if(ObtenerHeap(prueba)==false)
            {
                lol=ObtenerAsociadoMaximo(prueba);
                if(v[prueba].Volumen()>v[lol].Volumen())
                {
                    Intercambiar(lol,prueba);
                    FlotarMax(lol);
                }
            }
        }

        return borrado;
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
                        j=ObtenerAsociadoMaximo(i);
                        //cout << j << endl;
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
        TVectorPoro aux(posicion-1);

        for(i=0;i<posicion;i++)
        {
            aux[i]=v[i];
        }
        v=aux;

        int lol=0;
        for(int prueba=2;prueba<posicion;prueba++)
        {
            if(ObtenerHeap(prueba)==false)
            {
                lol=ObtenerAsociadoMaximo(prueba);
                if(v[prueba].Volumen()>v[lol].Volumen())
                {
                    Intercambiar(lol,prueba);
                    FlotarMax(lol);
                }
            }
        }
        return borrado;
}


TVectorPoro TDeapPoro::Niveles() const
{
     int i;

     TVectorPoro vNiveles(posicion-1);
     for(i=2;i<posicion;i++)
     {
          vNiveles[i]=v[i];
     }


     return vNiveles;
}


TVectorPoro TDeapPoro::Inorden() const
{
     TVectorPoro v(posicion-1);
     int pos=1, i=1;

     InordenAux(v,pos,i);

     return v;
}

TVectorPoro TDeapPoro::Preorden() const
{
     TVectorPoro v(posicion-1);
     int pos=1, i=1;

     PreordenAux(v,pos,i);

     return v;
}

TVectorPoro TDeapPoro::Postorden() const
{
     TVectorPoro v(posicion-1);
     int pos=1, i=1;

     PostordenAux(v,pos,i);

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

void TDeapPoro::PreordenAux(TVectorPoro &vi, int &pos, int i) const
{
     if(i<posicion) //Estoy en el Deap
     {
          vi[pos]=v[i];
          pos++;
          PreordenAux(vi,pos,2*i);
          PreordenAux(vi,pos,2*i+1);
     }
}

void 
TDeapPoro::PostordenAux(TVectorPoro &vi, int &pos, int i) const
{
     if(i<posicion) //Estoy en el Deap
     {
          PostordenAux(vi,pos,2*i);
          PostordenAux(vi,pos,2*i+1);
          vi[pos]=v[i];
          pos++;
     }
}

bool 
TDeapPoro::Buscar(const TPoro &p)
{
    bool encontrado=false;
    int i=2;
	TPoro b=p;
	TPoro a;
    while(i<posicion)
    {
		a=v[i];
		
        if(b.Volumen()==a.Volumen())
        {
            encontrado=true;
        }

        i++;
    }

    return encontrado;
}

TPoro 
TDeapPoro::Max() const
{
        TPoro poro;
        if(posicion>=4)
        {
            poro=v[3];
        }
        else if(posicion==3)
        {
            poro=v[2];
        }

        return poro;
}

TPoro 
TDeapPoro::Min() const
{
        TPoro poro;
        if(posicion>=3)
                poro=v[2];

        return poro;
}

int TDeapPoro::Altura() const
{
        int h=0,i;
        i=posicion-1;

        if(posicion!=2)
        {
            while(i>1)
            {
                    i=i/2;
                    h=h+1;
            }

            h++; //el nivel vacio
        }
        else
        {
            h=0;
        }

        return h;
}

int
TDeapPoro::Nodos() const
{
    int i=0;
    cout<<"debemos entrar aqui seguro"<<endl;
    if(posicion==2)
    {
		cout<<"debemos entrar aqui seguro"<<endl;
        i=0;
    }
    else
    {
        i=posicion-1;
    }
    return i;
}

ostream& operator<<(ostream &os, const TDeapPoro &deap)
{
    TVectorPoro vector;

    vector=deap.Niveles();

    os << vector;

    return os;
}
