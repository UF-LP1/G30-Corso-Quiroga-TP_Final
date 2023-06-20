#pragma once
#include <iostream>
#include <string>
#include "cPaciente.h"


using namespace std;

#ifndef _CCTERAPIA_H
#define _CCTERAPIA_H

class cPaciente;
class cDosimetrista;

class cTerapia{
protected:
	int gy;
	int cantSesiones;
	cDosimetrista* dosimetrista;
	cPaciente* paciente;
public:
	cTerapia(int gy, int cantSesiones);
	cTerapia(cDosimetrista* dosimetrista, cPaciente* paciente);
	~cTerapia();
	virtual int getTipoTerapia() = 0;
	virtual void AplicarTerapia(cPaciente* paciente) = 0;

	cPaciente* getpaciente() { return this->paciente; }
	//int getTerapia(cDosimetrista* dosimetrista);

};

#endif 