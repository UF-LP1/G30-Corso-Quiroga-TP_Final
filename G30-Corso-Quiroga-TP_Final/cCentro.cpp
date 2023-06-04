#include "cCentro.h"




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