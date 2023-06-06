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
	cPaciente* paciente; //hacer get y set
	cOncologo* oncologo; //hacer get y set
	cTumor* tumor;

public:
	cFicha(int acumRadiacion, cTerapia* terapia, cPaciente* paciente, cOncologo* oncologo);
	~cFicha();
	
	cTerapia* getterapia() { return this->terapia; }
	cTumor* gettumor() { return this->tumor; }
	
	int getacumRadiacion() { return this->acumRadiacion; }
	void setacumRadiacion(int acumRadiacion);
};

