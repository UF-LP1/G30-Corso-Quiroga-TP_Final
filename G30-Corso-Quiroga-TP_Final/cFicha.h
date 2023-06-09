#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "cTerapia.h"
#include "cPaciente.h"
#include "cOncologo.h"
#include "cTumor.h"

using namespace std;
class cPaciente;
class cTerapia;
class cOncologo;
class cTumor;

class cFicha
{
private:
	//cTime fecha;
	int acumRadiacion;
	cTerapia* terapia; 
	cPaciente* paciente; 
	cOncologo* oncologo; 
	cTumor* tumor; //borrar
	cLista <cTumor>* listaTumor;

public:
	cFicha(int acumRadiacion, cTerapia* terapia, cPaciente* paciente, cOncologo* oncologo);
	~cFicha();

	int getacumRadiacion() { return this->acumRadiacion; }
	void setacumRadiacion(int acumRadiacion);
	
	cTerapia* getterapia() { return this->terapia; }
	void setterapia(cTerapia* terapia);

	cPaciente* getpaciente() { return this->paciente; }
	void setpaciente(cPaciente* paciente);

	cOncologo* getoncologo() { return this->oncologo; }
	void setoncologo(cOncologo* oncologo);

	cTumor* gettumor() { return this->tumor; }
	void settumor(cTumor* tumor);
	
	void aplicarRadiacion(int radiacion);

	int getcantTumor();
	void agregarTumor(cTumor* tumor);
	void eliminarTumor(cTumor* tumor);
	cTumor* quitarTumor(cTumor* tumor);
};

