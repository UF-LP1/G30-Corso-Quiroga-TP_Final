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
	this->curado = false;
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

string cPaciente::to_string() {
	string result = "Paciente ";
	result += this->nombre;
	result += ", con DNI: ";
	result += this->DNI;
	result += " y numero de telefono: ";
	result += this->telefono;
	return result;
}

ostream& operator<<(ostream& out, cPaciente& paciente)
{ //accedo al m�todo to_string() de la clase cPaciente para obtener la representaci�n de cadena de texto del objeto paciente.
	out << paciente.to_string() << endl;
	return out;
}
