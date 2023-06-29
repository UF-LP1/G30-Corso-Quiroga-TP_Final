#include "cRadioterapiaSistemica.h"



cRadioterapiaSistemica::cRadioterapiaSistemica() : cTerapia(20, 8) {

}
cRadioterapiaSistemica::~cRadioterapiaSistemica() {}

int cRadioterapiaSistemica::getTipoTerapia() { return 3; }

int cRadioterapiaSistemica::AplicarTerapia(cLista <cTumor>* listaTumor) {

	//Veo las probabilidades de curación de un cancer
	float _probabilidad = rand() % +1;
	if (_probabilidad > 0.5) {
		int i = rand() % +listaTumor->getCA();
		listaTumor->Eliminar(i);
	}

	gy = rand() % 2 + 4;
	this->cantsesion++; //Calculo la dosis total que recibe el paciente correspondiente a este tipo de terapia
	return gy;
}