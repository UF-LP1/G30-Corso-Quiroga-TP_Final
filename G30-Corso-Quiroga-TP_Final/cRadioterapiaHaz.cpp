#include "cRadioterapiaHaz.h"

cRadioterapiaHaz::cRadioterapiaHaz() : cTerapia(20, 5) {
	
}



cRadioterapiaHaz::~cRadioterapiaHaz() {}

int cRadioterapiaHaz::getTipoTerapia() { return 1; }

int cRadioterapiaHaz::AplicarTerapia(cLista <cTumor>* listaTumor) {

	//Veo las probabilidades de curación de un cancer
	float _probabilidad = rand() % + 1;
	if (_probabilidad > 0.5) {
		int i = rand() % +listaTumor->getCA();
		listaTumor->Eliminar(i);
	}

	gy = rand() % 1 + 2;
	this->cantsesion++; //Calculo la dosis total que recibe el paciente correspondiente a este tipo de terapia
	return gy;
}