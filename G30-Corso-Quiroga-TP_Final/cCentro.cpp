#include "cCentro.h"




void cCentro::agregarPaciente(cPaciente* paciente) {
	this->listaPaciente->Insertar(paciente);
	try { this->listaPaciente->Insertar(paciente); }
	catch (exception) {} //Completar
}