#ifndef __PORO_H__
#define __PORO_H__

#include <iostream>
using namespace std;
//! \file tporo.h
//! \brief Cabeceras de la clase TPoro

//! \class TPoro
/*!	\brief Clase que construye los numeros complejos*/

class TPoro
{
	public:
		//! \brief Constructor por defecto de TComplejo
		/*!	Construye un Poro con argumentos a 0*/
		TPoro (int = 0, int = 0, double =0.0, char* =NULL);
		
		//! \brief Constructor de copia
		/*!	Construye un TPoro a partir de otro.*/
		TPoro (const TPoro&);
		
		//! \brief Destructor
		/*!	Hace que los argumentos del poro sean 0.*/
		~TPoro();
		
		//! \brief Operator=
		/*! Asigna un poro a otro.*/
		TPoro& operator= (const TPoro&);
		
		//! \brief Operator ==
		/*! Devuelve true si ambos poros son iguales.*/
		bool operator== (const TPoro&) const;
		
		//! \brief Operator !=
		/*! Devuelve true si ambos poros son distintos.*/
		bool operator!= (const TPoro&) const; 

		//! \brief Posicion
		/*! Modifica la posicion de un poro.*/
		void Posicion(int, int);
		
		//! \brief Volumen
		/*! Modifica el volumen de un poro.*/
		void Volumen(double);
		
		//! \brief Color
		/*! Modifica el color de un poro.*/
		void Color(char*);
		
		//! \brief PosicionX
		/*! Devuelve la coordenada x del poro.*/
		int PosicionX();
		
		//! \brief PosicionY
		/*! Devuelve la coordenada y del poro.*/
		int PosicionY();
		
		//! \brief Volumen
		/*! Devuelve el volumen del poro.*/
		double Volumen();
		
		//! \brief Color
		/*! Devuelve el color del poro.*/
		char* Color();
		
		//! \brief EsVacio
		/*! Devuelve true si ambos poros son distintos.*/
		bool EsVacio() const;
		
		friend ostream& operator<<(ostream &, const TPoro &);
	
	private:
	
		int x;
		int y;
		double volumen;
		char* color;

};
#endif
