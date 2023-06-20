#pragma once

#include <iostream>
#include <string>
#include "cTumor.h"
#include "cTerapia.h"
#include "cRadioterapiaHaz.h"
#include "cBraquiterapia.h"
#include "cRadioterapiaSistemica.h"

using namespace std;

class cTerapia;
class cTumor;

class cDosimetrista
{
	int tipoTerapia;
	cTerapia* terapia;
	cTumor* tumor;
public:
	cDosimetrista(int tipoTerapia);
	~cDosimetrista();
	//int calcularDosisTotal(); //CORREGIR
	cTerapia* determinarTipoTerapia(cLista<cTumor>* tumores); //CORREGIR
};

