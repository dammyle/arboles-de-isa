#ifndef __TCOLA_ABBPORO_H_
#define __TCOLA_ABBPORO_H_

#include <iostream>
using namespace std;

#include "tporo.h"
#include "tvectorporo.h"
#include "tabbporo.h"

class TABBPoro;
class TECAP;
class TColaABBPoro
{
	friend ostream &operator<<(ostream&, TColaABBPoro&);
	public:
		TColaABBPoro():primero(NULL), ultimo(NULL){};
		~TColaABBPoro();
		TColaABBPoro(const TColaABBPoro&);
		TColaABBPoro& operator=(const TColaABBPoro&);
		bool Encolar(TABBPoro* a);
		bool Desencolar();
		bool EsVacia(){return primero==NULL;};
		bool operator==(TColaABBPoro& );
		TColaABBPoro operator+(const TColaABBPoro &);
		TABBPoro* Cabeza();
		int Longitud();
		
	private:
		TECAP* primero;
		TECAP* ultimo;
};

class TECAP
{
	friend class TColaABBPoro;
	public:
		TECAP():arbol(NULL),sig(NULL){};
		TECAP(const TECAP &);
		~TECAP();
		TECAP& operator=(const TECAP&);
	
	private:
		TABBPoro* arbol;
		TECAP* sig;
};

#endif

