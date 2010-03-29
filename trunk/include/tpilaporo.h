/**
*
*
*\author Isabel Martín Herrero 48539974 S
*
*
**/

/**
*\file tlistaporo.h
*\brief Archivo .h de la clase tpilaporo
*Archivo que contiene la declaración la clase TPilaPoro
*
**/

#ifndef __TPILAPoro_H_
#define __TPILAPoro_H_

#include "tporo.h"
#include "tvectorporo.h"
#include <iostream>
using namespace std;

/** \brief Clase TPilaPoro
 * La clase TPilaPoro contiene un vector de la clase TPoro.
 */
class TPilaPoro
{
	public:
		/** \brief Constructor de la clase TPilaPoro
		* Crea un objeto de tipo TPilaPoro
		*/
		TPilaPoro();
		
		/** \brief Constructor de copia
		* Crea una copia del tipo TPilaPoro
		*/
		TPilaPoro(const TPilaPoro &p);
		
		/** \brief Destructor
		* Destruye la pila.
		*/
		~TPilaPoro();

		/** \brief Operator=
		* Iguala dos objetos pila.
		*/
		TPilaPoro & operator=(const TPilaPoro &);
		
		/** \brief Operator==
		* true si son iguales
		*/
		bool operator==(const TPilaPoro &p) const;
		
		/** \brief EsVacia
		* true si la pila esta vacia
		*/
		bool EsVacia() const;
		
		/** \brief Apilar
		* true si apila.
		*/
		bool Apilar(const TPoro&);
		
		/** \brief Desapilar
		* true si desapila correctamente.
		*/
		bool Desapilar();
		
		/** \brief Cima
		* Devuelve el TPoro que esta en cabeza.
		*/
		TPoro Cima() const;

		/** \brief Longitud
		* Devuelve la longitud de la pila.
		*/
		int Longitud() const;
		
		/** \brief operator+
		* Suma dos pilas
		*/
		TPilaPoro operator+(const TPilaPoro &) const;
		
		/** \brief Operator << de TPilaPoro
		*	Saca la pila por pantalla entre {}
		*/
		friend ostream & operator<<(ostream &,const TPilaPoro &);

	private:
		/** \brief Miembro v
		*vector de poros
		*/
		TVectorPoro v;
		
		/** \brief Miembro posicion
		* Devuelve la siguiente posicion vacia de la pila
		*/
		int posicion;
		
		/** \brief Miembro error
		* En caso de que el poro sea erroneo
		*/
		TPoro error;
};

#endif
