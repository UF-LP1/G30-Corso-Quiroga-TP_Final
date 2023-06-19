#pragma once

#include <iostream>
#include <string>
#include "cTumor.h"
#include "cTerapia.h"

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
	int calcularDosisTotal(); //CORREGIR
	int determinarTipoTerapia(cTumor* tumor); //CORREGIR
};

