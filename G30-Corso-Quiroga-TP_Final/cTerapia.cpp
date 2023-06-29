#include "cTerapia.h"

cTerapia::cTerapia(int gy, int cantSesiones) {
	this->gy = gy;
	this->cantSesiones = cantSesiones;

}


cTerapia::~cTerapia() {}
void cTerapia::setcantsesion(int cantsesiones)
{
	this->cantsesion = cantsesion;
	return;
}
/*
int getTerapia(cDosimetrista* dosimetrista) {

	//int tipoterapia = dosimetrista->determinarTipoTerapia();
	//return tipoterapia;
}//COREGIR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

eTipoTerapia cTerapia::getTipoTerapia(eTipoTerapia tipoTerapia) {

	if (tipoTerapia == 1)
		return this->terapia = radioterapiaHaz;
	else if (tipoTerapia == 2)
		return this->terapia = braquiterapia;
	else if (tipoTerapia == 3)
		return this->terapia = radioterapiaSistemica;

}