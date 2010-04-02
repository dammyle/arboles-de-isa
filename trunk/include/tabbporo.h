#ifndef __TABBPORO_H_
#define __TABBPORO_H_

#include "tporo.h"
#include "tlistaporo.h"

//! \file tabbporo.h
//! \brief Cabeceras de la clase TABBPoro, TNodoABB

class TNodoABB;

//! \class TNodoABB
/*!	\brief Clase que implementa un árbol binario de busqueda*/
class TABBPoro
{
	friend class TNodoABB;
 	
	friend ostream & operator<<(ostream &, TABBPoro &);
 	public:	 	
		//! \brief Constructor por defecto de TA234Com
		/*!	Construye un arbol 234 vacio*/
		TABBPoro();
		//! \brief Constructor de copia de TA234Com
		/*!	Construye un árbol 234 copia de otro*/
		TABBPoro(const TABBPoro &);
		//! \brief Destructor de TA234Com
		/*!	Libera la memoria ocupada del árbol AVL*/
		~TABBPoro();
		//! \brief Operador =
		/*!	Asigna un árbol 234 a otro*/
		TABBPoro& operator=(const TABBPoro &);
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
		TPoto Raiz() const ;
		//! \brief Nodos
		/*!	Devuelve el número de nodos del árbol*/
		int Nodos() const;
		//! \brief NodosHoja
		/*!	Devuelve el número de nodos del árbol sin hijos*/
		int NodosHoja() const;
		//! \brief Niveles
		/*!	Devuelve el recorrido por niveles del árbol*/
		TListaCom Niveles() const;

		//! \brief operator+
		/*! Suma de dos arboles binarios de busqueda:*/
		TABBPoro operator+(TABBPoro &);

		//! \ brief opertor 
		/*! Resta de dos arboles  binarios de busqueda;*/
		TABBPoro operator-(TABBPoro &);
		
		//! \brief Inorden
		/*!	Devuelve el recorrido Inorden del árbol*/
		TVectorPoro Inorden() const;

		TVectorPoro Preorden() const;

		TVectorPoro Postorden() const;

		TVectorPoro Niveles() const;
		//! \brief Borrar
		/*!	Borra un TComplejo y devuelve true si lo consigue*/
		bool Borrar(const TPoro&);
		
		bool Comprobar();
			
	private:
		//! \brief TA234Nodo *raiz
		/*!	Raíz del arbol AVL*/
		TNodoABB *nodo;
		
		bool reemplazar(TABBPoro, TABBPoro);
		//! \brief NivelesAux
		/*!	Método privado que devuelve el recorrido niveles en la lista pasada como argumento*/
		void NivelesAux(TListaCom&) const;
		//! \brief InordenAux
		/*!	Método privado que devuelve el recorrido Inorden en la lista pasada como argumento*/
		void InordenAux(TListaCom&) const;
};

//! \class TA234Nodo
/*!	\brief Clase que implementa un nodo de un árbol 234*/
class TNodoABB
{
	friend class TABBPoro;
	public:
	
		//! \brief Constructor por defecto de TA234Nodo
		/*!	Construye un nodo de árbol 234*/
		TNodoABB();
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
		
		
	private:	
		
		TPoro item;
		TABBPoro iz, de;
};

class TNodoABB;

//! \class TA234Cola
/*!	\brief Clase que implementa una cola de punteros a TA234Nodo*/
class TA234Cola
{
	public:
		//! \brief Constructor por defecto de TA234Cola
		/*!	Crea una cola de punteros a TA234Nodo vacía*/
		TA234Cola():principio(NULL), fin(NULL){};
		//! \brief Destructor de TA234Cola
		/*!	Libera la memoria de una cola*/
		~TA234Cola();
		//! \brief Encolar
		/*!	Añade un puntero a TA234Com al final de la cola*/
		void Encolar(const TA234Com* a);
		//! \brief EsVacia
		/*!	Devuelve true si la cola es vacía*/
		TA234Com* Desencolar();
		//! \brief Desencolar
		/*!	Borra el primer elemento de la cola*/
		bool Esvacia(){return principio==NULL;};
		
	private:
		//! \brief TA234CNodo* principio
		/*!	Cabeza de la cola*/
		TA234ColaNodo *principio;
		//! \brief TA234CNodo* fin
		/*!	Final de la cola*/
	
		TA234ColaNodo *fin;
};



//! \class TA234ColaNodo
/*!	\brief Clase que implementa un nodo de cola de punteros a T234Com*/
class TA234ColaNodo
{
	friend class TA234Cola;
	public:
		//! \brief Constructor por defecto de TA234ColaNodo
		/*!	Crea un nodo de cola de punteros a TA234ColaNodo vacío*/
		TA234ColaNodo():n(NULL),sig(NULL){};
		//! \brief Constructor sobrecargado de TA234ColaNodo
		/*!	Crea un nodo de cola de punteros a TA234ColaNodo con el puntero a árbol a*/
		TA234ColaNodo(TA234Com* a):n(a),sig(NULL){};
		//! \brief Constructor de copia TA234ColaNodo
		/*!	Crea un nodo de cola de punteros a TA234ColaNodo copia de otro*/
		TA234ColaNodo(const TA234ColaNodo& nodo);
		//! \brief Destructor de TA234ColaNodo
		/*! Libera la memoria de un nodo*/
		~TA234ColaNodo();
		
	private:
		//! \brief TA234ColaNodo* n
		/*!	Puntero a árbol que almacenamos*/
		TA234Com *n;
		//! \brief TA234ColaNodo* sig
		/*!	Siguiente elemento de la cola*/
		TA234ColaNodo *sig;
};



#endif
