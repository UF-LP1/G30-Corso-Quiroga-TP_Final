#pragma once
#include <iostream>
#include <string>
#include "cLista.h"
#include "cPaciente.h"
#include "cOncologo.h"
using namespace std;

class cCentro
{
private:
	cLista <cPaciente>* listaPaciente;
	cLista <cOncologo>* listaOncologo;

public:

	void agregarPaciente(cPaciente* paciente);

	void agregarOncologo(cOncologo* oncologo);


};

