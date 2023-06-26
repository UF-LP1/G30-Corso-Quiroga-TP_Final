#ifndef _CRADIOTERAPIAHAZ_H
#define _CRADIOTERAPIAHAZ_H

class cTerapia;
class cPaciente;
#include <iostream>
#include <string>
#include "cTerapia.h"

using namespace std;

class cRadioterapiaHaz: public cTerapia
{

public:
	cRadioterapiaHaz(int gy, int cantSesiones);
	cRadioterapiaHaz();
	~cRadioterapiaHaz();
	
	void AplicarTerapia(cPaciente* paciente);
};
#endif
