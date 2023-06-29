#ifndef _CRADIOTERAPIASISTEMICA_H
#define _CRADIOTERAPIASISTEMICA_H



#include <iostream>
#include <string>
#include "cTerapia.h"

class cTerapia;


class cRadioterapiaSistemica : public cTerapia
{
public:
	cRadioterapiaSistemica(int gy, int cantSesiones);
	cRadioterapiaSistemica();
	~cRadioterapiaSistemica();
	
	int AplicarTerapia();
};
#endif