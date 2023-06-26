#include "cRadioterapiaHaz.h"

cRadioterapiaHaz::cRadioterapiaHaz(int gy, int cantSesiones) : cTerapia(gy, cantSesiones) {
	this->gy = gy;
	this->cantSesiones = cantSesiones;
}

cRadioterapiaHaz::cRadioterapiaHaz() : cTerapia(gy, cantSesiones) {
	this->gy = 20;
	this->cantSesiones = 5;
}



cRadioterapiaHaz::~cRadioterapiaHaz() {}


void cRadioterapiaHaz::AplicarTerapia(cPaciente* paciente) {

	int radiacion = gy / cantSesiones;
	cFicha* ficha = paciente->getficha();
	if (ficha->getacumRadiacion() + radiacion >= 100) {
		throw new exception("No se puede continuar con la terapia");
	}
	ficha->aplicarRadiacion(radiacion);
}