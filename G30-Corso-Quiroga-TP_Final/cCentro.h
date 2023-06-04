#pragma once
#include <iostream>
#include <string>
#include "cLista.h"
#include "cPaciente.h"
using namespace std;

class cCentro
{
private:
	cLista <cPaciente>* listaPaciente;

public:

	void agregarPaciente(cPaciente* paciente);


};

