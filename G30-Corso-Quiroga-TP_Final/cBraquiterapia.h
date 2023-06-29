#ifndef _CBRAQUITERAPIA_H
#define _CBRAQUITERAPIA_H

class cTerapia;
class cPaciente;

#include <iostream>
#include <string>
#include "cTerapia.h"

using namespace std;

class cBraquiterapia : public cTerapia {
public:
	
	cBraquiterapia();
	~cBraquiterapia();

	int AplicarTerapia(cLista <cTumor>* listaTumor);
	int getTipoTerapia();

};
#endif