#ifndef _CRADIOTERAPIAHAZ_H
#define _CRADIOTERAPIAHAZ_H

//class cTerapia;
//class cPaciente;
#include <iostream>
#include <string>
#include "cTerapia.h"

using namespace std;

class cRadioterapiaHaz : public cTerapia
{

public:
	
	cRadioterapiaHaz();
	~cRadioterapiaHaz();

	int AplicarTerapia(cLista <cTumor>* listaTumor);
	int getTipoTerapia();
};
#endif
