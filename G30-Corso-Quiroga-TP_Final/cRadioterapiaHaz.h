#ifndef _CRADIOTERAPIAHAZ_H
#define _CRADIOTERAPIAHAZ_H


#include <iostream>
#include <string>
#include "cTerapia.h"


class cPaciente;

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
