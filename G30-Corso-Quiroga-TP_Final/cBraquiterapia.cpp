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



int cBraquiterapia::AplicarTerapia(cLista <cTumor>* listaTumor) {

	//Veo las probabilidades de curación de un cancer
	float _probabilidad = rand() % +1;
	if (_probabilidad > 0.6) {
		int i = rand() % +listaTumor->getCA();
		listaTumor->Eliminar(i);
	}

	gy = rand() % 6 + 8;
	this->cantsesion++; //Calculo la dosis total que recibe el paciente correspondiente a este tipo de terapia
	return gy;
}