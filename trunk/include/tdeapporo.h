#ifndef TDEAPPORO_H_
#define TDEAPPORO_H_
#include <iostream>
#include "tvectorporo.h"
using namespace std;


enum THEAP {HEAP_MINIMO, HEAP_MAXIMO};

class TDeapPoro{
public:
    // Constructor por defecto
    TDeapPoro();
    // Constructor de copia
    TDeapPoro(TDeapPoro &);
    // Destructor
    ~TDeapPoro();
    // Sobrecarga del operador asignación
    TDeapPoro & operator=(TDeapPoro &);
    // MÉTODOS
    // Sobrecarga del operador igualdad
    bool operator==(TDeapPoro &);
    // Devuelve TRUE si el deap está vacío, FALSE en caso contrario
    bool EsVacio();
    // Inserta el elemento en el deap
    bool Insertar(const TPoro &);
    // Borra el elemento máximo en el deap
    bool BorrarMax();
    // Borra el elemento mínimo en el deap
    bool BorrarMin();
    // Devuelve el elemento máximo en el deap
    TPoro Max();
    // Devuelve el elemento mínimo en el deap
    TPoro Min();
    // Devuelve la altura del deap (la altura de un deap vacío es 0)
    int Altura();
    // Devuelve el número de nodos del deap (un deap vacío posee 0 nodos)
    int Nodos();
    // Devuelve  el recorrido en inorden
    TVectorPoro  Inorden() const;
    // Devuelve  el recorrido en preorden
    TVectorPoro  Preorden();
    // Devuelve  el recorrido en postorden
    TVectorPoro  Postorden();
    // Devuelve el recorrido por niveles
    TVectorPoro Niveles() const;
    friend ostream & operator<<(ostream &, TDeapPoro &);

private:
    THEAP ObtenerHeap(int i) const;
    int ObtenerAsociadoMaximo(int i) const;
    int ObtenerAsociadoMinimo(int j) const;
    void Intercambiar(int i, int j);
    void FlotarMinimo(int i);
    void FlotarMaximo(int j);
    void InordenAux(TVectorPoro &vi, int &pos, int i) const;
    bool Buscar(const TPoro &p);
    // Almacena los poros
    TVectorPoro v;
    // Indica la próxima posición libre en el vector
    int posicion;

};

#endif /*TDEAPPORO_H_*/
