#pragma once
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
	cTumor(eTamanio tamanio,eUbicacion ubicacion,int acumRadiacion);
	~cTumor();

	eTamanio gettamanio() { return this->tamanio; }
	void settamanio(eTamanio tamanio);
	eUbicacion getubicacion() { return this->ubicacion; }
	void setubicacion(eUbicacion ubicacion);
	int getacumRadiacion() { return this->acumRadiacion; }
	void setacumRadiacion(int acumRadiacion);

};

