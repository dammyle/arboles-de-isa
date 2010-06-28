#ifndef __TCOLA_ABBPORO_H_
#define __TCOLA_ABBPORO_H_

#include <iostream>
using namespace std;

#include "tporo.h"
#include "tvectorporo.h"
#include "tabbporo.h"

/** \file tcolaabbporo.h
* \brief .h de la cola
* Definicion de las clases de la cola
*/

class TABBPoro;
class TECAP;

/** \class TColaABBPoro
* \brief Clase TColaABBPoro
* Clase completa para construir TColaABBPoro
*/
class TColaABBPoro
{

    friend class TECAP;
    friend class TNodoABB;

    private:
        /** \brief TECAP* primero
        *       Variable que representa el primer elemento de la cola
        */
        TECAP *primero;
        /** \brief TECAP* ultimo
        *       Variable que representa el ultimo elemento de la cola
        */
        TECAP *ultimo;
    public:
        /** \brief Constructor por defecto
        * Construye un objeto TColaABBPoro con valores inicializados
        */
        TColaABBPoro():primero(NULL),ultimo(NULL){};
        /** \brief Constructor de copia
        * Crea una copia del objeto que recibe
        * \param c Cola de la que copiar
        */
        TColaABBPoro(const TColaABBPoro &);
        /** \brief Destructor
        * Destruye el objeto liberando memoria de las variables
        */
        ~TColaABBPoro();
        /** \brief Sobrecarga del operador asignación
        * Copia los valores de un objeto a otro
        * \param cola Cola de la que copiar
        * \return Objeto copiado
        */
        TColaABBPoro & operator=(const TColaABBPoro &);
        /** \brief Sobrecarga del operador igualdad
        * Compara los dos objetos y devuelve un bool
        * \param cola Cola a comparar
        * \return Devuelve si es verdadero o falso
        */
        bool operator==(TColaABBPoro &);
        /** \brief Sobrecarga del operador suma
        * Hace la suma de dos colas
        * \param cola Cola a sumar
        * \return Devuelve la suma
        */
        TColaABBPoro operator+(const TColaABBPoro &);
       
        /** \brief EsVacia()
        * Mira si la cola es vacia o no
        * \return Devuelve si es verdadero o falso
        */
        bool EsVacia() {return primero==NULL && ultimo==NULL;};
        /** \brief Encolar
        * Encola un poro en la cola
        * \param a Poro a encolar
        * \return Devuelve si es verdadero o falso
        */
        bool Encolar(TABBPoro *);
        /** \brief Desencolar
        * Desencola un poro de la cola
        * \return Devuelve si es verdadero o falso
        */
        bool Desencolar();
        /** \brief Sobrecarga del operador igualdad
        * Compara los dos objetos y devuelve un bool
        * \param poro Poro a comparar
        * \return Devuelve si es verdadero o falso
        */
        TABBPoro * Cabeza() const;
        /** \brief Longitud
        * Saca la longitud de la cola
        * \return Devuelve un entero que representa la cantidad de poros
        */
        int Longitud() const;
        /** \brief Sobrecarga del operador SALIDA
        * Imprime el contenido del objeto
        * \param os Tipo ostream&
        * \param colaabb Objeto TColaABBPoro
        * \return ostream&
        */
        friend ostream & operator<<(ostream &, const TColaABBPoro &);
        friend ostream & operator<<(ostream &, const TPoro &);


};
/** \class TECAP
* \brief Clase TECAP
* Clase completa para construir TECAP
*/
class TECAP
{
    friend class TColaABBPoro;
    friend class TABBPoro;
    friend class TNodoABB;

    private:
        /** \brief arbol
        *       Variable que representa el contenido del nodo
        */
        TABBPoro *arbol;
        /** \brief sig
        *       Variable que representa el siguiente nodo
        */
        TECAP *sig;

    public:
        /** \brief Constructor por defecto
        * Construye un objeto TECAP con valores inicializados
        */
        TECAP ():arbol(NULL),sig(NULL){};
        /** \brief Constructor de copia
        * Crea una copia del objeto que recibe
        * \param nodo Nodo del que copiar
        */
        TECAP (const TECAP &);
        /** \brief Destructor
        * Destruye el objeto liberando memoria de las variables
        */
        ~TECAP ();
        /** \brief Sobrecarga del operador asignación
        * Copia los valores de un objeto a otro
        * \param nodo Nodo del que copiar
        * \return Objeto copiado
        */
        TECAP & operator=(const TECAP &);
        friend ostream & operator<<(ostream &, const TColaABBPoro &);

};

#endif

