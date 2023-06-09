#pragma once
#include <iostream>
#include <string>
#include "cTerapia.h"

using namespace std;

class cRadioterapiaSistemica : public cTerapia
{

public:
	cRadioterapiaSistemica(int gy, int cantSesiones);
	~cRadioterapiaSistemica();
	int getTipoTerapia();
	void AplicarTerapia(cPaciente* paciente);
};

