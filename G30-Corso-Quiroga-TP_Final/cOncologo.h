#pragma once
#include <iostream>
#include <string>
#include "cTumor.h"
#include "cLista.h"
#include "cPaciente.h"
#include "cTerapia.h"
#include "cDosimetrista.h"

using namespace std;
class cTumor;
class cPaciente;
class cTerapia;

class cOncologo{

private:
	string nombre;
	int ID;
	cTerapia* terapia;
	cDosimetrista* dosimetrista;
public:
	static cLista<cTumor>* tumores;
	cOncologo(string nombre, int ID);
	~cOncologo();
	int suministrarDosis();  
	void frecuencia(); 

	cLista <cTumor>* encontrarTumores(cPaciente* paciente);
	string getnombre() { return this->nombre; }
	void setnombre(string nombre);
	int getID() { return this->ID; }
	void setID(int ID);
};

