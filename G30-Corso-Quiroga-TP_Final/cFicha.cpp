#include "cFicha.h"

cFicha::cFicha(cTerapia* terapia, cPaciente* paciente, cOncologo* oncologo, time_t fecha) {
	this->acumRadiacion = 0;
	this->sesionPracticada = 0;
	this->oncologo = oncologo;
	this->paciente = paciente;
	this->listaTumor = new cLista<cTumor>(10);
	this->fecha = fecha;
}

cFicha::cFicha(cPaciente* paciente)
{
}

cFicha::~cFicha() {
	delete listaTumor;
}

void cFicha::setacumRadiacion(float acumRadiacion)
{
	this->acumRadiacion = acumRadiacion;
	return;
}

void cFicha::setsesion(int sesionPracticada)
{
	this->sesionPracticada = sesionPracticada;
	return;
}

void cFicha::setcantsesion(int cantsesion)
{
	this->cantsesion = cantsesion;
	return;
}

void cFicha::setterapia(cTerapia* terapia)
{
	this->terapia = terapia;
	return;
}

string cFicha::to_string() {
	string tratamiento;
	if (dynamic_cast<cBraquiterapia*>(this->terapia) != nullptr)
		tratamiento = "braquiterapia";
	else if (dynamic_cast<cRadioterapiaHaz*>(this->terapia) != nullptr)
		tratamiento = "radioterapia de haz externo";
	else if (dynamic_cast<cRadioterapiaSistemica*>(this->terapia) != nullptr)
		tratamiento = "radioterapia sistemica";
	string paciente = this->paciente->to_string();
	string oncologo = this->oncologo->to_string();
	return "Paciente: " + paciente + "Oncologo: " + oncologo + "Tratamiento: " + tratamiento;
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
	this->listaTumor->Insertar(tumor);
	return;
}

void cFicha::aplicarRadiacion(float radiacion) {
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

bool cFicha::encontrarRadicionLimite() {
	int i;
	bool toR = false;
	for (i = 0; i < this->listaTumor->getCA(); i++) {
		cTumor* _tumor = listaTumor->Buscar(i);
		int dosis = 0;
		if (dynamic_cast<cBraquiterapia*>(this->getterapia()) != nullptr)
			dosis = 160;
		if (dynamic_cast<cRadioterapiaHaz*>(this->getterapia()) != nullptr)
			dosis = 10;
		if (dynamic_cast<cRadioterapiaSistemica*>(this->getterapia()) != nullptr)
			dosis = 100;

		if (_tumor->getacumradiacion() / dosis > 0.95) {
			toR = true;
			break;
		}

		return toR;

	}
}