#ifndef _CRADIOTERAPIAHAZ_H
#define _CRADIOTERAPIAHAZ_H



#include <iostream>
#include <string>
#include "cTerapia.h"

class cTerapia;


class cRadioterapiaHaz: public cTerapia
{

public:
	cRadioterapiaHaz(int gy, int cantSesiones);
	cRadioterapiaHaz();
	~cRadioterapiaHaz();
	
	int AplicarTerapia();
};
#endif
