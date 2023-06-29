#ifndef _CONCOLOGO_H
#define _CONCOLOGO_H
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
class cDosimetrista;

class cOncologo {

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
	//void frecuencia(); 
	string to_string();

	cLista <cTumor>* encontrarTumores(cPaciente* paciente);
	string getnombre() { return this->nombre; }
	void setnombre(string nombre);
	int getID() { return this->ID; }
	void setID(int ID);
	void darAlta(cPaciente* paciente);
};
#endif
