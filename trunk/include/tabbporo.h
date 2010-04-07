#ifndef __TABBPORO_H_
#define __TABBPORO_H_

#include "tporo.h"
#include "tlistaporo.h"

//! \file tabbporo.h
//! \brief Cabeceras de la clase TABBPoro, TNodoABB

//! \class TNodoABB
/*!	\brief Clase que implementa un árbol binario de busqueda*/

class TNodoABB;

class TABBPoro
{
	friend class TNodoABB;
 	
	friend ostream & operator<<(ostream &, TABBPoro &);
 	public:	 	
		//! \brief Constructor por defecto de TA234Com
		/*!	Construye un arbol 234 vacio*/
		TABBPoro():nodo(NULL){};
		//! \brief Constructor de copia de TA234Com
		/*!	Construye un árbol 234 copia de otro*/
		TABBPoro(const TABBPoro &);
		//! \brief Destructor de TA234Com
		/*!	Libera la memoria ocupada del árbol AVL*/
		~TABBPoro();
		//! \brief Operador =
		/*!	Asigna un árbol 234 a otro*/
		TABBPoro & operator=(const TABBPoro &);
		//! \brief Operador ==
		/*!	Devuelve verdadero si ambos árboles son iguales*/
		bool operator==(const TABBPoro &) const;
		//! \brief Operador != 
		/*!	Devuelve verdadero si los árboles son distintos*/
		bool operator!=(const TABBPoro &a) const{ return !operator==(a);};
		//! \brief EsVacio
		/*!	Devuelve true si el árbol 234 está vacio*/
		bool EsVacio() const ;
		//! \brief Insertar
		/*!	Inserta un TComplejo en el árbol y devuelve true si lo consigue*/
		bool Insertar(const TPoro &);
		//! \brief Buscar
		/*!	Devuelve true si el TComplejo ha sido previamente insertado*/
		bool Buscar(const TPoro&) const;
		//! \brief Altura
		/*!	Devuelve la altura del árbol (niveles que tendra)*/
		int Altura() const ;
		//! \brief Raiz
		/*!	Devuelve el elemento en la raiz del arbol*/
		TPoro Raiz() const ;
		//! \brief Nodos
		/*!	Devuelve el número de nodos del árbol*/
		int Nodos() const;
		//! \brief NodosHoja
		/*!	Devuelve el número de nodos del árbol sin hijos*/
		int NodosHoja() const;
		//! \brief Niveles
		/*!	Devuelve el recorrido por niveles del árbol*/
		TVectorPoro Niveles() const;

		//! \brief operator+
		/*! Suma de dos arboles binarios de busqueda:*/
		TABBPoro operator+(TABBPoro &) const;

		//! \ brief opertor 
		/*! Resta de dos arboles  binarios de busqueda;*/
		TABBPoro operator-(TABBPoro &) const;
		
		//! \brief Inorden
		/*!	Devuelve el recorrido Inorden del árbol*/
		TVectorPoro Inorden() const;
		void InordenAux(TVectorPoro&, int) const;
		TVectorPoro Preorden() const;
		void PreordenAux(TVectorPoro&, int) const;
		TVectorPoro Postorden() const;
		void PostordenAux(TVectorPoro&, int) const;
		bool Borrar(const TPoro&);
			
	private:
		TNodoABB* nodo;
		bool reemplazar(TABBPoro, TABBPoro );// en el borrado, reemplazas por el menor de la iquierda
		
};

class TNodoABB
{
	friend class TABBPoro;
	public:
	
		//! \brief Constructor por defecto de TA234Nodo
		/*!	Construye un nodo de árbol 234*/
		TNodoABB(){};
		//! \brief Constructor de copia de TA234Nodo
		/*!	Construye un nodo de árbol 234 copia de otro*/
		TNodoABB(const TNodoABB&);
		//! \brief Destructor de TA234Nodo
		/*!	Libera la memoria de un nodo*/
		~TNodoABB();
		//! \brief Operador = 
		/*!	Asigna T234Nodo*/
		TNodoABB& operator=(const TNodoABB&);
		//! \brief Operador == 
		/*!	Compara dos T234Nodo*/
		bool operator==(const TNodoABB&) const;
		bool operator!=(const TNodoABB& a)const {return !operator==(a);}
		
	private:	
		
		TPoro item;
		TABBPoro iz, de;
};


class TECAP
{
	friend class TABBPoro;
	public:
		TECAP():arbol(NULL),sig(NULL){};
		TECAP(const TECAP &);
		~TECAP();
		TECAP& operator=(const TECAP&);
	
	private:
		TABBPoro* arbol;
		TECAP* sig;
};

class TColaABBPoro
{
	friend class TECAP;
	friend ostream &operator<<(ostream&, TColaABBPoro&);
	public:
		TColaABBPoro():primero(NULL), ultimo(NULL){};
		~TColaABBPoro();
		TColaABBPoro(TColaABBPoro&);
		TColaABBPoro& operator=(TColaABBPoro&);
		bool Encolar(const TABBPoro* a);
		bool Desencolar();
		bool Esvacia(){return primero==NULL;};
		bool operator==(TColaABBPoro& );
		TColaABBPoro operator+(TColaABBPoro &);
		TABBPoro* Cabeza();
		int Longitud();
		
	private:
		TECAP* primero;
		TECAP* ultimo;
};


#endif
