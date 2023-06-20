#include "cTerapia.h"

cTerapia::cTerapia(int gy, int cantSesiones) {
	this->gy = gy;
	this->cantSesiones = cantSesiones;
	
}
cTerapia::cTerapia(cDosimetrista* dosimetrista, cPaciente* paciente) {
	this->dosimetrista = dosimetrista;
	this->paciente = paciente;
}
cTerapia::~cTerapia() {}
/*
int getTerapia(cDosimetrista* dosimetrista) {

	//int tipoterapia = dosimetrista->determinarTipoTerapia();
	//return tipoterapia;
}//COREGIR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/