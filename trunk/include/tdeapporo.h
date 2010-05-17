#ifndef TDEAPPORO_H_
#define TDEAPPORO_H_
#include <iostream>
#include "tvectorporo.h"
using namespace std;

class TDeapPoro
{
	friend class TVectorPoro;
	friend ostream & operator<<(ostream &, TDeapPoro &);
	
	public:
		// Constructor por defecto
		TDeapPoro();
		// Constructor de copia
		TDeapPoro(const TDeapPoro &);
		// Destructor
		~TDeapPoro();
		// Sobrecarga del operador asignación
		TDeapPoro & operator=(const TDeapPoro &);
		// MÉTODOS
		// Sobrecarga del operador igualdad
		bool operator==(const TDeapPoro &);
		// Devuelve TRUE si el deap está vacío, FALSE en caso contrario
		bool EsVacio(){return posicion==2;};
		// Inserta el elemento en el deap
		bool Insertar(const TPoro &);
		// Borra el elemento máximo en el deap
		bool BorrarMax();
		// Borra el elemento mínimo en el deap
		bool BorrarMin();
		// Devuelve el elemento máximo en el deap
		TPoro Max(){if(v.Longitud()>=4) return v[3];};
		// Devuelve el elemento mínimo en el deap
		TPoro Min(){if(v.Longitud()>=3) return v[2];};
		// Devuelve la altura del deap (la altura de un deap vacío es 0)
		int Altura() const;
		// Devuelve el número de nodos del deap (un deap vacío posee 0 nodos)
		int Nodos(){return v.Longitud();};
		// Devuelve  el recorrido en inorden
		TVectorPoro  Inorden() const;
		// Devuelve  el recorrido en preorden
		TVectorPoro  Preorden() const;
		// Devuelve  el recorrido en postorden
		TVectorPoro  Postorden()const;
		// Devuelve el recorrido por niveles
		TVectorPoro Niveles() const;
		

	private:
		bool ObtenerHeap(int i) const;
		int ObtenerAsociadoMaximo(int i) const;
		int ObtenerAsociadoMinimo(int j) const;
		void Intercambiar(int i, int j);
		void FlotarMinimo(int i);
		void FlotarMaximo(int j);
		void InordenAux(TVectorPoro &, int &, int ) const;
		void PreordenAux(TVectorPoro &, int &, int) const;
		void PostordenAux(TVectorPoro &, int &, int) const;
		bool Buscar(const TPoro &p);
		// Almacena los poros
		TVectorPoro v;
		// Indica la próxima posición libre en el vector
		int posicion;
		
		bool THeap;//0 minimo; 1 maximo

};

#endif
