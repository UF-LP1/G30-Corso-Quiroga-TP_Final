#include "cRadioterapiaHaz.h"

cRadioterapiaHaz::cRadioterapiaHaz(int gy, int cantSesiones) : cTerapia(gy, cantSesiones) {
	
}

cRadioterapiaHaz::cRadioterapiaHaz() : cTerapia(20, 5) {
	
}



cRadioterapiaHaz::~cRadioterapiaHaz() {}


int cRadioterapiaHaz::AplicarTerapia() {
	
	
	gy = rand() % 1 + 10; //Calculo la dosis total que recibe el paciente correspondiente a este tipo de terapia
	
	float radiacion = gy / cantSesiones;
	return radiacion;
	/*cFicha* ficha = paciente->getficha();
	if (ficha->getacumRadiacion() + radiacion >= 100) {
		throw new exception("No se puede continuar con la terapia");
	}
	ficha->aplicarRadiacion(radiacion);*/
}