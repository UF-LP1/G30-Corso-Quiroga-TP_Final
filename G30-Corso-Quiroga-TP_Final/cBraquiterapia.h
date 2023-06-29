#ifndef _CBRAQUITERAPIA_H
#define _CBRAQUITERAPIA_H



#include <iostream>
#include <string>
#include "cTerapia.h"

class cTerapia;


class cBraquiterapia: public cTerapia {
public:
	cBraquiterapia(int gy, int cantSesiones);
	cBraquiterapia();
	~cBraquiterapia();
	
	int AplicarTerapia();

};
#endif
