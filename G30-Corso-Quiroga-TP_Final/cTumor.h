#ifndef _CTUMOR_H
#define _CTUMOR_H
#include <iostream>
#include <string>
#include "eTamanio.h"
#include "eUbicacion.h"

using namespace std;

class cTumor
{
private:
	eTamanio tamanio;
	eUbicacion ubicacion;
	int acumRadiacion;

public:
	cTumor(eTamanio tamanio, eUbicacion ubicacion, int acumRadiacion);
	cTumor();
	~cTumor();

	eTamanio gettamanio() { return this->tamanio; }
	void settamanio(eTamanio tamanio);
	eUbicacion getubicacion() { return this->ubicacion; }
	void setubicacion(eUbicacion ubicacion);
	int getacumradiacion() { return this->acumRadiacion; }
	void setacumradiacion(int acumRadiacion);

};
#endif
