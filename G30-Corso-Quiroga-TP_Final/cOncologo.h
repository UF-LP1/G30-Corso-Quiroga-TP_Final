#pragma once
#include <iostream>
#include <string>
#include "cTumor.h"
#include "cLista.h"
#include "cPaciente.h"

using namespace std;
class cTumor;
class cPaciente;
class cOncologo{

private:
	string nombre;
	int ID;
public:
	static cLista<cTumor>* tumores;
	cOncologo(string nombre, int ID);
	~cOncologo();
	void suministrarDosis();  //CORREGIR
	void frecuencia(); //CORREGIR

	cLista <cTumor>* encontrarTumores(cPaciente* paciente);
	string getnombre() { return this->nombre; }
	void setnombre(string nombre);
	int getID() { return this->ID; }
	void setID(int ID);
};

