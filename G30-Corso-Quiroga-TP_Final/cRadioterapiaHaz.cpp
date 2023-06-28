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
	
	
	gy = rand() % 1 + 10; //Calculo la dosis total que recibe el paciente correspondiente a este tipo de terapia
	
	float radiacion = gy / cantSesiones;

	cFicha* ficha = paciente->getficha();
	if (ficha->getacumRadiacion() + radiacion >= 100) {
		throw new exception("No se puede continuar con la terapia");
	}
	ficha->aplicarRadiacion(radiacion);
}