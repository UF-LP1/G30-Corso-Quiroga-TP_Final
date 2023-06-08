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

int cPaciente::getcantTumor() {
	
	return this->listaTumor->getCA();
}

void cPaciente::agregarTumor(cTumor* tumor) {
	this->listaTumor->Insertar(tumor);
	try { this->listaTumor->Insertar(tumor); }
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

void cPaciente::eliminarTumor(cTumor* tumor){ //si encuentro la posicion del tumor en la lista lo elimino
	int pos = listaTumor->BuscarAtPos(tumor);
	if (pos != -1) {
		cTumor* tumorEliminado = listaTumor->QuitarPos(pos);
		delete tumorEliminado;
	}

}

cTumor* cPaciente::quitarTumor(cTumor* tumor){ //verifico si el tumor en la pos actual es igual al tumor que quiero quitar
	int i;
	for (i = 0; i < listaTumor->getCA(); i++) { //si encuentro el tumor, lo quito de la lista
		if (listaTumor->Buscar(i) == tumor) {
			return listaTumor->Quitar(i);
		}
	}
	return nullptr; //retorno nullptr si no encontre el tumor en la lista
}

//falta hacer la de buscar. Buscar por ubicacion de tumor????