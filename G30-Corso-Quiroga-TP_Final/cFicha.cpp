#include "cFicha.h"

cFicha::cFicha(int acumRadiacion, cTerapia* terapia, cPaciente* paciente, cOncologo* oncologo) {
	this->acumRadiacion = acumRadiacion;

}

cFicha::~cFicha() {}

void cFicha::setacumRadiacion(int acumRadiacion)
{
	this->acumRadiacion = acumRadiacion;
	return;
}