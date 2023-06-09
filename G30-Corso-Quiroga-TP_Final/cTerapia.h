#pragma once
#include <iostream>
#include <string>
#include "cPaciente.h"

using namespace std;
class cPaciente;

class cTerapia{
protected:
	int gy;
	int cantSesiones;
public:
	cTerapia(int gy, int cantSesiones);
	~cTerapia();
	virtual int getTipoTerapia() = 0;
	virtual void AplicarTerapia(cPaciente* paciente) = 0;

};

