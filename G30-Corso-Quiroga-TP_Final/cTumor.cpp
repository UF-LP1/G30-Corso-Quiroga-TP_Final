#include "cTumor.h"
cTumor::cTumor(eTamanio tamanio, eUbicacion ubicacion, int acumRadiacion) {
	this->tamanio = tamanio;
	this->ubicacion = ubicacion;
	this->acumRadiacion = acumRadiacion;
}
cTumor::cTumor() {
	this->tamanio = eTamanio::grande;
	this->ubicacion = eUbicacion::ojo;
	this->acumRadiacion = 0;
}
cTumor::~cTumor() {}

void cTumor::settamanio(eTamanio tamanio)
{
	this->tamanio = tamanio;
	return;
}

void cTumor::setubicacion(eUbicacion ubicacion)
{
	this->ubicacion = ubicacion;
	return;
}

void cTumor::setacumradiacion(int acumRadiacion)
{
	this->acumRadiacion = acumRadiacion;
	return;
}