#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#include "cPaciente.h"

cPaciente::cPaciente(string nombre, int DNI, string sexo, int telefono, eTipoSangre tipoSangre, float salud)
{
	this->nombre = nombre;
	this->DNI = DNI;
	this->sexo = sexo;
	this->telefono = telefono;
	this->tipoSangre = tipoSangre;
	this->salud = salud;

	this->listaTumor = new cLista<cTumor>(10);


}

cPaciente::~cPaciente() {}

void cPaciente::setnombre(string nombre)
{
	this->nombre = nombre;
	return;
}

void cPaciente::setsexo(string sexo)
{
	this->sexo = sexo;
	return;
}

void cPaciente::settelefono(int telefono)
{
	this->telefono = telefono;
	return;
}

void cPaciente::settiposangre(eTipoSangre tipoSangre)
{
	this->tipoSangre = tipoSangre;
	return;
}

void cPaciente::setsalud(float salud)
{
	this->salud = salud;
	return;
}

int cPaciente::getcantTumor() {
	
	return this->listaTumor->getCA();
}

void cPaciente::agregarTumor(cTumor* tumor) {
	this->listaTumor->Insertar(tumor);
	try { this->listaTumor->Insertar(tumor); }
	catch (exception) {} //Completar
}

//implementar cPaciente (eliminar tumor, ubicar tumor)