#pragma once
#include <iostream>
#include <string>
#include "cTerapia.h"

using namespace std;

class cRadioterapiaHaz: public cTerapia
{

public:
	cRadioterapiaHaz(int gy, int cantSesiones);
	~cRadioterapiaHaz();
	int getTipoTerapia();
	void AplicarTerapia(cPaciente* paciente);
};

