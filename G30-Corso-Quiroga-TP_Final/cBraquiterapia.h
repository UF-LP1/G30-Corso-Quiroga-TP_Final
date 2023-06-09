#pragma once
#include <iostream>
#include <string>
#include "cTerapia.h"

using namespace std;

class cBraquiterapia : public cTerapia
{
public:
	cBraquiterapia(int gy, int cantSesiones);
	~cBraquiterapia();
	int getTipoTerapia();
	void AplicarTerapia(cPaciente* paciente);

};

