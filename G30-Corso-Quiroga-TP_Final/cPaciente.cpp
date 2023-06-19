#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#include "cPaciente.h"

cPaciente::cPaciente(string nombre, int DNI, string sexo, int telefono, eTipoSangre tipoSangre, float salud, time_t fechaNac)
{
	this->nombre = nombre;
	this->DNI = DNI;
	this->sexo = sexo;
	this->telefono = telefono;
	this->tipoSangre = tipoSangre;
	this->salud = salud;
	this->fechaNac = fechaNac;
}

cPaciente::~cPaciente() {}

void cPaciente::setnombre(string nombre)
{
	this->nombre = nombre;
	return;
}

void cPaciente::setDNI(int DNI)
{
	this->DNI = DNI;
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

void cPaciente::setficha(cFicha* ficha)
{
	this->ficha = ficha;
	return;
}

