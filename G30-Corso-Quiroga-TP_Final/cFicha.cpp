#include "cFicha.h"

cFicha::cFicha(int acumRadiacion, cTerapia* terapia, cPaciente* paciente, cOncologo* oncologo) {
	this->acumRadiacion = acumRadiacion;

	this->listaTumor = new cLista<cTumor>(10);
}

cFicha::cFicha(cPaciente* paciente)
{
}

cFicha::~cFicha() {
	//destruir listas
}

void cFicha::setacumRadiacion(int acumRadiacion)
{
	this->acumRadiacion = acumRadiacion;
	return;
}

void cFicha::setterapia(cTerapia* terapia)
{
	this->terapia = terapia;
	return;
}

void cFicha::setpaciente(cPaciente* paciente)
{
	this->paciente = paciente;
	return;
}

void cFicha::setoncologo(cOncologo* oncologo)
{
	this->oncologo = oncologo;
	return;
}

void cFicha::settumor(cTumor* tumor)
{
	this->tumor = tumor;
	return;
}

void cFicha:: aplicarRadiacion(int radiacion) {
	this->acumRadiacion = this->acumRadiacion + radiacion;
	int i;
	for (i = 0; i < this->listaTumor->getCA(); i++) {
		cTumor* tumor = this->listaTumor->Buscar(i);
		tumor->setacumradiacion(radiacion + tumor->getacumradiacion());
	}
}


int cFicha::getcantTumor() {

	return this->listaTumor->getCA();
}

void cFicha::agregarTumor(cTumor* tumor) {
	this->listaTumor->Insertar(tumor);
	try { this->listaTumor->Insertar(tumor); }
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

void cFicha::eliminarTumor(cTumor* tumor) { //si encuentro la posicion del tumor en la lista lo elimino
	int pos = listaTumor->BuscarAtPos(tumor);
	if (pos != -1) {
		cTumor* tumorEliminado = listaTumor->QuitarPos(pos);
		delete tumorEliminado;
	}

}

cTumor* cFicha::quitarTumor(cTumor* tumor) { //verifico si el tumor en la pos actual es igual al tumor que quiero quitar
	int i;
	for (i = 0; i < listaTumor->getCA(); i++) { //si encuentro el tumor, lo quito de la lista
		if (listaTumor->Buscar(i) == tumor) {
			return listaTumor->Quitar(i);
		}
	}
	return nullptr; //retorno nullptr si no encontre el tumor en la lista
}

//falta hacer la de buscar. Buscar por ubicacion de tumor????