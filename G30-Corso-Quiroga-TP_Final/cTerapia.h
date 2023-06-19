#pragma once
#include <iostream>
#include <string>
#include "cPaciente.h"
#include "cTerapia.h"

using namespace std;
class cPaciente;
class cDosimetrista;

class cTerapia{
protected:
	int gy;
	int cantSesiones;
	cDosimetrista* dosimetrista;
public:
	cTerapia(int gy, int cantSesiones);
	~cTerapia();
	virtual int getTipoTerapia() = 0;
	virtual void AplicarTerapia(cPaciente* paciente) = 0;

	int getTerapia(cDosimetrista* dosimetrista);

};

