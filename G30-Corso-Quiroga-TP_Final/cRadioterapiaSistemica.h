#ifndef _CRADIOTERAPIASISTEMICA_H
#define _CRADIOTERAPIASISTEMICA_H

class cTerapia;
class cPaciente;

#include <iostream>
#include <string>
#include "cTerapia.h"

using namespace std;

class cRadioterapiaSistemica : public cTerapia
{
public:
	
	cRadioterapiaSistemica();
	~cRadioterapiaSistemica();

	int AplicarTerapia(cLista <cTumor>* listaTumor);
	int getTipoTerapia();
};
#endif