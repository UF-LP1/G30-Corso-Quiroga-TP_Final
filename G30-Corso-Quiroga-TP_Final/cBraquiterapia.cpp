#include "cBraquiterapia.h"



cBraquiterapia::cBraquiterapia() : cTerapia(20, 5) {
	
}
cBraquiterapia::~cBraquiterapia() {}

int cBraquiterapia::getTipoTerapia() { return 2; }


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