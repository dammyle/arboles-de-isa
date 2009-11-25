#ifndef __TPILAPoro_H_
#define __TPILAPoro_H_

#include "tporo.h"
#include "tvectorporo.h"
#include <iostream>
using namespace std;
//! \file tpilaporo.h
//! \brief Cabeceras de la clase TPilaPoro

//! \class TPilaPoro
/*!	\brief Clase que emula una pila a partir de un vector*/

class TPilaPoro
{
	public:
		//! \brief Constructor por defecto de TPilaPoro
		/*!	Construye un objeto de tipo TPilaPoro*/
		TPilaPoro();
		//! \brief Constructor de copia de TPilaPoro
		/*!	Construye un objeto de tipo TPilaPoro a partir de otro*/
		TPilaPoro(const TPilaPoro &p);
		//! \brief Destructor de TPilaPoro
		/*!	Libera la memoria dinámica de la pila*/
		~TPilaPoro();
		//! \brief Operator = de TPilaPoro
		/*!	Asigna una pila a otra*/
		TPilaPoro & operator=(const TPilaPoro &);
		//! \brief Operator == de TPilaPoro
		/*!	Devuelve true si las 2 pilas tienen los mismos elementos en el mismo orden*/
		bool operator==(const TPilaPoro &p) const;
		//! \brief EsVacia
		/*!	Devuelve true si la pila esta vacia*/
		bool EsVacia() const;
		//! \brief Apilar
		/*!	Añade un elemento delante de la pila*/
		bool Apilar(const TPoro&);
		//! \brief Desapilar
		/*!	Borra el elemento de la cima de la pila*/
		bool Desapilar();
		//! \brief Cima
		/*!	Devuelve el valor del TPoro en la cima de la pila*/
		TPoro Cima() const;
		//! \brief Longitud
		/*!	Devuelve la longitud del vector que emula la pila*/
		int Longitud() const;
		
		//! \brief Operator + de TPilaPoro
		/*!	Devuelve una pila con los elementos de this mas los del argumento*/
		TPilaPoro operator+(const TPilaPoro &) const;
		
		//! \brief Operator << de TPilaPoro
		/*!	Saca la pila por pantalla entre <>*/
		friend ostream & operator<<(ostream &,const TPilaPoro &);

	private:
		//! \brief TVectorPoro v
		/*!	Vector que almacena los datos de la pila*/
		TVectorPoro v;
		
		//! \brief int posicion
		/*!	Siguiente posicion vacia*/
		int posicion;
		
		//! \brief TPoro error
		/*!	Caso de que haya error*/
		TPoro error;
};

#endif
