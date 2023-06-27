#pragma once
#ifndef _CDOSIMETRISTA_H
#define _CDOSIMETRISTA_H
#include <iostream>
#include <string>
#include "cTumor.h"
#include "cLista.h"
#include "cTerapia.h"
#include "cRadioterapiaHaz.h"
#include "cBraquiterapia.h"
#include "cRadioterapiaSistemica.h"
#include "eTipoTerapia.h"

using namespace std;

class cTerapia;
class cTumor;

class cDosimetrista
{
	friend class cTerapia;
	eTipoTerapia tipoTerapia;
	cTerapia* terapia;
	cTumor* tumor;
public:
	cDosimetrista();
	~cDosimetrista();
	//int calcularDosisTotal(); 
	cTerapia* determinarTipoTerapia(cLista<cTumor>* tumores); 
};
#endif