#include "cBraquiterapia.h"

cBraquiterapia::cBraquiterapia(int gy, int cantSesiones) : cTerapia(gy, cantSesiones) {

}

cBraquiterapia::cBraquiterapia() : cTerapia(gy, cantSesiones) {
	this->gy = 20;
	this->cantSesiones = 5;
}
cBraquiterapia::~cBraquiterapia() {}

int cBraquiterapia::getTipoTerapia() { return 2; }

void cBraquiterapia::AplicarTerapia(cPaciente* paciente) {

	int radiacion = gy / cantSesiones;
	cFicha* ficha = paciente->getficha();
	if (ficha->getacumRadiacion() + radiacion >= 100) {
		throw new exception("No se puede continuar con la terapia");
	}
	ficha->aplicarRadiacion(radiacion);
}