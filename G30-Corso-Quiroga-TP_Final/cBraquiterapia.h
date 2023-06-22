#ifndef _CBRAQUITERAPIA_H
#define _CBRAQUITERAPIA_H

class cTerapia;
class cPaciente;

#include <iostream>
#include <string>
#include "cTerapia.h"

using namespace std;

class cBraquiterapia: public cTerapia {
public:
	cBraquiterapia(int gy, int cantSesiones);
	cBraquiterapia();
	~cBraquiterapia();
	eTipoTerapia getTipoTerapia();
	void AplicarTerapia(cPaciente* paciente);

};
#endif
