#include <iostream>
#include <string>
#include "cTumor.h"
#include "cLista.h"
using namespace std;

#ifndef _CCTERAPIA_H
#define _CCTERAPIA_H

class cTumor;

class cTerapia {
protected:
	int gy;
	int cantsesion;


public:
	cTerapia(int gy, int cantSesiones);

	~cTerapia();
	virtual int getTipoTerapia() = 0;
	//Ahora aplicar terapia retorna la radioación
	virtual int AplicarTerapia(cLista <cTumor>* listaTumor) = 0;
	void setcantsesion(int cantsesiones);

};

#endif