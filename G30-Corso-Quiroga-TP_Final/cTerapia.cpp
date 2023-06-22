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