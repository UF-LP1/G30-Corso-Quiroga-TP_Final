#ifndef _CBRAQUITERAPIA_H
#define _CBRAQUITERAPIA_H



#include <iostream>
#include <string>
#include "cTerapia.h"

class cTerapia;
class cPaciente;

using namespace std;

class cBraquiterapia: public cTerapia {
public:
	cBraquiterapia(int gy, int cantSesiones);
	cBraquiterapia();
	~cBraquiterapia();
	
	void AplicarTerapia(cPaciente* paciente);

};
#endif
