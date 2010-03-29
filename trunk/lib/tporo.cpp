#include <iostream>
using namespace std;
#include "tporo.h"
#include <math.h>
#include <string>
#include <cstring>
#include <stdlib.h>

//! \file tporo.cpp
//! \brief Implementacion de la clase TPoro

TPoro::TPoro(int nx, int ny, double ent,char* nc):x(nx), y(ny), volumen(ent) 
{
	int longi = 0;
	int i = 0;
		

	if (nc!=NULL)
	{
		longi = strlen(nc)+1;
		char c[longi];		
		color = new char(longi);
		strcpy(c,nc);
		while (i<longi)
		{
			if (c[i]>='A' && c[i]<='Z')
			{
				c[i]=c[i]+32;
			}
			else c[i]=c[i];
			i++;
		}
		c[i]='\0';
		strcpy(color,c);
	}
	else color = nc;
}

TPoro::TPoro(const TPoro & n)
{
	x=n.x;
	y=n.y;
	volumen=n.volumen;
	color=n.color;
}

TPoro::~TPoro()
{
	x=y=0;
	volumen=0.0;
	if (color!=NULL)
	{
		color=NULL;
	}
}

TPoro&
TPoro::operator= (const TPoro& n)
{
	if (this != &n)
	{
		x=n.x;
		y=n.y;
		volumen=n.volumen;
		color=n.color;	
	}
	return *this;	
}

bool
TPoro::operator==(const TPoro& n) const
{
	return(x==n.x && y==n.y && volumen==n.volumen && color==n.color);
}

bool
TPoro::operator!= (const TPoro& n) const
{
	return (&n==this);
}

void 
TPoro::Posicion(int nx, int ny)
{
	x=nx;
	y=ny;
}

void
TPoro::Volumen(double v)
{
	volumen=v;
}

void 
TPoro::Color(char* nc)
{
	int i=0;
	string c;
	if (nc!=NULL)
	{
		c=nc;
		while (i<(int)c.length() && c!="")
		{
			
			if (c[i]>='A' && c[i]<='Z')
			{
				c[i]=c[i]+32;
			}
			else c[i]=c[i];
			i++;
		}
		color=(char*)c.c_str();
	}

}

int 
TPoro::PosicionX()
{
	return x;
}
int
TPoro::PosicionY()
{
	return y;
}

double
TPoro::Volumen()
{
	return volumen;
}

char* 
TPoro::Color()
{
	return color;
}
		
bool 
TPoro::EsVacio() const
{
	bool ret;
	if (x==0 && y==0  && volumen==0.0 && color==NULL)
	{
		ret=true;//esta vacio
	}
	else ret=false;
	
	return ret;
}

ostream& 
operator<< (ostream &os, const TPoro &n)
{
	bool vacio=false;

	if (n.EsVacio() )
	{
		os<<'('<<')';
		vacio=true;
	}
	
	if(!vacio && n.color==NULL)
	{ 

		os.setf(ios::fixed);
		os.precision( 2 );
		char menos='-';
		os <<'(' <<n.x <<", " <<n.y <<')' <<" "<<n.volumen<<" "<<menos;
	}
	
	if(!vacio && n.color!=NULL)
	{
		os.setf(ios::fixed);
		os.precision( 2 );
		os <<'(' <<n.x <<", "<<n.y <<')' <<" "<<n.volumen<<" "<<n.color;
	}

	return os;
}
