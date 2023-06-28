#include "cBraquiterapia.h"

cBraquiterapia::cBraquiterapia(int gy, int cantSesiones) : cTerapia(gy, cantSesiones) {
	this->gy = gy;
	this->cantSesiones = cantSesiones;
}

cBraquiterapia::cBraquiterapia() : cTerapia(gy, cantSesiones) {
	this->gy = 20;
	this->cantSesiones = 5;
}
cBraquiterapia::~cBraquiterapia() {}



void cBraquiterapia::AplicarTerapia(cPaciente* paciente) {

	gy = rand() % 100 + 160;  //Calculo la dosis total que recibe el paciente correspondiente a este tipo de terapia

	float radiacion = gy / cantSesiones;
	cFicha* ficha = paciente->getficha();
	if (ficha->getacumRadiacion() + radiacion >= 150) {
		throw new exception("No se puede continuar con la terapia");
	}
	ficha->aplicarRadiacion(radiacion);
}