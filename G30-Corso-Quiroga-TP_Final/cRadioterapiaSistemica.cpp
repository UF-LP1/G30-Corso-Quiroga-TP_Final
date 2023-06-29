#include "cRadioterapiaSistemica.h"

cRadioterapiaSistemica::cRadioterapiaSistemica(int gy, int cantSesiones) : cTerapia(gy, cantSesiones) {
	
}
cRadioterapiaSistemica::cRadioterapiaSistemica() : cTerapia(20, 5) {

}
cRadioterapiaSistemica::~cRadioterapiaSistemica() {}



int cRadioterapiaSistemica::AplicarTerapia() {

	gy = rand() % 20 + 40; //Calculo la dosis total que recibe el paciente correspondiente a este tipo de terapia

	float radiacion = gy / cantSesiones;
	return radiacion;
	/*cFicha* ficha = paciente->getficha();
	if (ficha->getacumRadiacion() + radiacion >= 100) {
		throw new exception("No se puede continuar con la terapia");
	}
	ficha->aplicarRadiacion(radiacion);*/
}