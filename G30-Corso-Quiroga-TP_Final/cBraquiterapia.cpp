#include "cBraquiterapia.h"

cBraquiterapia::cBraquiterapia(int gy, int cantSesiones) : cTerapia(gy, cantSesiones) {
	
}

cBraquiterapia::cBraquiterapia() : cTerapia(20, 5) {
	
}
cBraquiterapia::~cBraquiterapia() {}



int cBraquiterapia::AplicarTerapia() {

	gy = rand() % 100 + 160;  //Calculo la dosis total que recibe el paciente correspondiente a este tipo de terapia

	float radiacion = gy / cantSesiones;
	return radiacion;
	
	/*cFicha* ficha = paciente->getficha();
	if (ficha->getacumRadiacion() + radiacion >= 150) {
		throw new exception("No se puede continuar con la terapia");
	}
	ficha->aplicarRadiacion(radiacion);*/
}