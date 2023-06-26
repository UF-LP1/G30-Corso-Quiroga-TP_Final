#include "cRadioterapiaSistemica.h"

cRadioterapiaSistemica::cRadioterapiaSistemica(int gy, int cantSesiones) : cTerapia(gy, cantSesiones) {
	this->gy = gy;
	this->cantSesiones = cantSesiones;
}
cRadioterapiaSistemica::cRadioterapiaSistemica() : cTerapia(gy, cantSesiones) {
	this->gy = 20;
	this->cantSesiones = 5;
}
cRadioterapiaSistemica::~cRadioterapiaSistemica() {}



void cRadioterapiaSistemica::AplicarTerapia(cPaciente* paciente) {

	int radiacion = gy / cantSesiones;
	cFicha* ficha = paciente->getficha();
	if (ficha->getacumRadiacion() + radiacion >= 150) {
		throw new exception("No se puede continuar con la terapia");
	}
	ficha->aplicarRadiacion(radiacion);
}