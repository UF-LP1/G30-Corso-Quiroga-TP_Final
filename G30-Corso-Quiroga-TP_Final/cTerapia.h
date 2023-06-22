#ifndef _CTERAPIA_H
#define _CTERAPIA_H

class cPaciente;

#include <iostream>
#include <string>
#include "cPaciente.h"
#include "eTipoTerapia.h"

using namespace std;

class cTerapia{
protected:
	int gy;
	int cantSesiones;
	cPaciente* paciente;
	eTipoTerapia terapia;
	int cantsesion;
public:
	cTerapia(int gy, int cantSesiones);
	~cTerapia();

	virtual eTipoTerapia getTipoTerapia() = 0;
	virtual void AplicarTerapia(cPaciente* paciente) = 0;

	int getcantsesion() { return this->cantsesion; }
	void setcantsesion(int cantsesiones);

	cPaciente* getpaciente() { return this->paciente; }
	

};

#endif 