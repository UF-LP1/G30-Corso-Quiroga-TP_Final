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

	gy = rand() % 20 + 40; //Calculo la dosis total que recibe el paciente correspondiente a este tipo de terapia

	float radiacion = gy / cantSesiones;
	cFicha* ficha = paciente->getficha();
	if (ficha->getacumRadiacion() + radiacion >= 100) {
		throw new exception("No se puede continuar con la terapia");
	}
	ficha->aplicarRadiacion(radiacion);
}