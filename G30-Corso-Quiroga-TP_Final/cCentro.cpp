#include "cCentro.h"


cCentro::cCentro() {

	this->listaPaciente = new cLista<cPaciente>(maxPaciente);
	this->listaOncologo = new cLista<cOncologo>(maxOncologo);
	
}
cCentro::~cCentro() {
	//destruir los objetos de las listas y las listas
}

void cCentro::agregarPaciente(cPaciente* paciente) {
	this->listaPaciente->Insertar(paciente);
	try { this->listaPaciente->Insertar(paciente); }
	catch (exception) {} //Completar
}

void cCentro::agregarOncologo(cOncologo* oncologo) {
	this->listaOncologo->Insertar(oncologo);
	try { this->listaOncologo->Insertar(oncologo); }
	catch (exception) {} //Completar
}

cLista <cPaciente>* cCentro::buscarPacienteTyC(cTerapia* terapia, eUbicacion ubicacion) {
	cLista <cPaciente>* ToR= new cLista <cPaciente> (this->listaPaciente->getCA());
	int i;
	for (i = 0; i < this->listaPaciente->getCA(); i++) {
		cPaciente* paciente = this->listaPaciente->Buscar(i);  //devuelve el paciente en la pos i
		if (paciente->getficha()!= NULL && paciente->getficha()->getterapia()->getTipoTerapia() == terapia->getTipoTerapia()) {
			if(paciente->getficha()->gettumor()->getubicacion() == ubicacion) {
				ToR->Insertar(paciente);
			}
		}

	}
	return ToR;
}