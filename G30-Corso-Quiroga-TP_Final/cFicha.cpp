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

void cFicha::setterapia(cTerapia* terapia)
{
	this->terapia = terapia;
	return;
}

void cFicha::setpaciente(cPaciente* paciente)
{
	this->paciente = paciente;
	return;
}

void cFicha::setoncologo(cOncologo* oncologo)
{
	this->oncologo = oncologo;
	return;
}

void cFicha::settumor(cTumor* tumor)
{
	this->tumor = tumor;
	return;
}


