/**
*
*
*\author Isabel Martín Herrero 48539974 S
*
*
**/

/**
*\file tlistaporo.h
*\brief Archivo .h de la clase tlistaporo
*Archivo que contiene la declaración la clase TListaPoro
*
**/

#ifndef __TLISTAPORO_H__
#define __TLISTAPORO_H__


#include "tvectorporo.h"
#include "tpilaporo.h"
#include "tporo.h" 
#include <iostream>
using namespace std;

class TPilaPoro;
class TListaPoro;

/** \brief Clase TListaNodo
 * La clase TListaNodo contiene un TPoro y dos punteros anterior y siguiente
 */

class TListaNodo
{
	friend class TListaPosicion;
	friend class TListaPoro;
	friend class TPilaPoro;
	public:
		/** \brief Constructor de la clase TListaNodo
		* Crea un objeto de tipo TListaNodo
		*/
		TListaNodo ();
		
		/** \brief Constructor de copia de la clase TListaNodo
		* Crea un objeto de tipo TListaNodo
		*/
		TListaNodo (const TListaNodo &);
		
		/** \brief Destructor de la clase TListaNodo
		* Libera toda la memoria de la clase TListaNodo
		*/
		~TListaNodo ();
		
		/** \brief Operator= 
		* Iguala el objeto this con el TListaNodo que pasan por parametro.
		*/
		TListaNodo & operator=(const TListaNodo &);

		/** \brief Sobrecarga del operador de salida de TListaPoro
		* Función amiga. Sobrecarga el operador de flujo de entrada para que lea un fichero y saque datos de él
		*/
		friend ostream & operator<<(ostream &, const TListaPoro &);

		/** \brief Sobrecarga del operador de salida de TPilaPoro
		* Función amiga. Sobrecarga el operador de flujo de entrada para que lea un fichero y saque datos de él
		*/
		friend ostream & operator<<(ostream &, const TPilaPoro &);
		
	private:
	
		/** \brief Miembro TPoro
		*Objeto que contiene al poro;
		*/
		TPoro e;
		/** \brief Miembro anterior
		*puntero al nodo anterior;
		*/
		TListaNodo *anterior;
		/** \brief Miembro siguiente
		*puntero al nodo siguiente;
		*/
		TListaNodo *siguiente;
};


/** \brief Clase TListaPosicion
 * La clase TListaPosicion, contiene un puntero a TListaNodo
 */
class TListaPosicion
{
	friend class TListaPoro;
	friend class TPilaPoro;
	friend class TListaNodo;
	public:
		/** \brief Constructor de la clase TListaPosicion
		* Construye una posicion de la lista
		*/
		TListaPosicion ():pos(0){};
		/** \brief Constructor de copia de TListaPosicion
		* Construye un objeto identico a this.
		*/
		TListaPosicion(const TListaPosicion &);
		
		/** \brief Destructor de TListaPosicion
		* Libera la memoria de TListaPosicion
		*/
		~TListaPosicion ();
		
		/** \brief Operator=
		* Iguala el objeto this al pasado por parametro
		*/
		TListaPosicion & operator=(const TListaPosicion &);

		/** \brief Operator==
		* True si son iguales.
		*/
		bool operator==(const TListaPosicion & p)const;
		
		/** \brief Operator!=
		* False si son iguales.
		*/
		bool operator!=(const TListaPosicion & p)const;
		
		/** \brief Anterior
		* Retorna la posicion anterior a la actual
		*/
		TListaPosicion Anterior() const;
		
		/** \brief Siguiente
		* Retorna la posicion siguiente a la actual
		*/
		TListaPosicion Siguiente() const;
		
		/** \brief EsVacia
		* True si la lista esta vacia.
		*/
		bool EsVacia(){return pos == NULL;};
		
		/** \brief Sobrecarga del operador de salida de TListaPosicion
		* Función amiga. Sobrecarga el operador de flujo de entrada para que lea un fichero y saque datos de él
		*/
		friend ostream & operator<<(ostream &, const TListaPosicion&);
		
		/** \brief Sobrecarga del operador de salida de TPilaPoro
		* Función amiga. Sobrecarga el operador de flujo de entrada para que lea un fichero y saque datos de él
		*/
		friend ostream & operator<<(ostream &, const TPilaPoro &);
	private:
		
		/** \brief Miembro pos
		*puntero al nodo.
		*/
		TListaNodo *pos;
};

/** \brief Clase TListaPoro
 * La clase TListaPoro, contiene un punteros a las posiciones primera y ultima
 */
class TListaPoro
{
	public:
		/** \brief Constructor de TListaPoro
		* Construye un objeto de tipo TListaPoro
		*/
		TListaPoro ():primero(NULL), ultimo(NULL){};
		
		/** \brief Constructor de copia de TListaPoro
		* Construye un objeto igual a this
		*/
		TListaPoro (const TListaPoro &);
		
		/** \brief Destructor de TListaPoro
		* Libera la memoria de TListaPoro
		*/
		~TListaPoro ();
		
		/** \brief Operator=
		* Iguala el objeto this al pasado por parametro
		*/
		TListaPoro & operator=(const TListaPoro &);
		
		/** \brief Operator==
		* True si son iguales.
		*/
		bool operator==(const TListaPoro &) const;
		
		/** \brief Operator!=
		* False si son iguales.
		*/
		bool operator!=(const TListaPoro &) const;
		
		/** \brief Operator+
		* Suma de dos listas
		*/
		TListaPoro operator+(const TListaPoro &) const;

		/** \brief Operator-
		* Resta de dos listas
		*/
		TListaPoro operator-(const TListaPoro &) const;
		
		/** \brief EsVacia
		* true si es esta vacia;
		*/
		bool EsVacia() const;
		
		/** \brief Insertar
		* true si se ha insertado correctamente;
		*/
		bool Insertar(const TPoro&);
		
		/** \brief Borrar
		* true si ha borrado correctamente;
		*/
		bool Borrar(const TPoro &);
		
		/** \brief Borrar
		* true si ha borrado correctamente;
		*/
		bool Borrar(const TListaPosicion &);
		
		/** \brief Obtener
		* Devualve el tporo que hay en la posicion pasada por parametro
		*/
		TPoro Obtener(const TListaPosicion &) const;

		/** \brief Buscar
		* Devuelve cierto si se ha encontrado el poro.
		*/
		bool Buscar(const TPoro &) const;
		
		/** \brief Primera
		* Devuelve la primera posicon de la lista.
		*/
		TListaPosicion Primera() const;
		
		/** \brief Ultima
		* Devuelve la ultima posicon de la lista.
		*/
		TListaPosicion Ultima() const;
		
		/** \brief Longitud
		* Devuelve la longitud de la lista
		*/
		int Longitud() const;
		
		/** \brief Sobrecarga del operador de salida de TListaPoro
		* Función amiga. Sobrecarga el operador de flujo de entrada para que lea un fichero y saque datos de él
		*/
		friend ostream & operator<<(ostream &, const TListaPoro &);
		
	private:
		/** \brief Miembro primero
		*puntero al nodo, primero
		*/
		TListaNodo *primero;
		
		/** \brief Miembro ultimo
		*puntero al nodo, ultimo.
		*/
		TListaNodo *ultimo;
		
		/** \brief PerteneceALista
		*Devuelve true si una TListaPosicion pertenece a la lista (private)
		*/
		bool PerteneceALista(const TListaPosicion &) const;

};
#endif
