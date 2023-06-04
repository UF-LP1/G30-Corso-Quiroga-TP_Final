#include "cFicha.h"

cFicha::cFicha(int acumRadiacion) {
	this->acumRadiacion = acumRadiacion;

}

cFicha::~cFicha() {}

void cFicha::setacumRadiacion(int acumRadiacion)
{
	this->acumRadiacion = acumRadiacion;
	return;
}