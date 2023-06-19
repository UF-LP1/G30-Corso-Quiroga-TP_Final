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
	catch (exception & e) {
		cout << e.what() << endl;
	} 
}

void cCentro::eliminarPaciente(cPaciente* paciente){ //si encuentro la posicion del paciente en la lista lo elimino
	int pos = listaPaciente->BuscarAtPos(paciente);
	if (pos != -1) {
		cPaciente* eliminarPaciente = listaPaciente->QuitarPos(pos);
		delete eliminarPaciente;
	}
}

void cCentro::agregarOncologo(cOncologo* oncologo) {
	this->listaOncologo->Insertar(oncologo);
	try { this->listaOncologo->Insertar(oncologo); }
	catch (exception & e) {
		cout << e.what() << endl;
	} 
}

void cCentro::eliminarOncologo(cOncologo* oncologo){ //si encuentro la posicion del oncologo en la lista lo elimino
	int pos = listaOncologo->BuscarAtPos(oncologo);
	if (pos != -1) {
		cOncologo* eliminarOncologo = listaOncologo->QuitarPos(pos);
		delete eliminarOncologo;
	}
}

void cCentro::crearFicha(cPaciente* paciente){
	//chequear que el paciente este
	int i = rand() % 0 + listaOncologo->getCA();
	cOncologo* oncologo = listaOncologo->Buscar(i);

	int j = rand() % 0 + listaPaciente->getCA();
	paciente = listaPaciente->Buscar(j);

	//int terapia = this->getTipoTerapia;

	//cFicha* ficha = new cFicha(0, terapia, paciente, oncologo);
} //ASI???????????????????



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

void cCentro::listarPacientes(){ //verifico si el paciente tiene una ficha, si es así, puedo obtener el tumor y su ubicacion y listarlo con el resto de datos
	int i;
	for (i = 0; i < listaPaciente->getCA(); i++) {
		cPaciente* paciente = listaPaciente->Buscar(i);
		cOncologo* oncologo = paciente->getficha()->getoncologo();
		cout << "Paciente" << i + 1 << ":" << endl;
		cout << "Nombre:" << paciente->getnombre() << endl;
		cout << "DNI:" << paciente->getDNI() << endl;
		cout << "Oncologo " << i + 1 << ":" << endl;
		cout << "Nombre Oncologo: " << oncologo->getnombre() << endl;
		cout << "ID Oncologo: " << oncologo->getID() << endl;
		cout << endl;
		if (paciente->getficha() != NULL) { //si no tiene una ficha entonces no imprime estos ultimos datos
			cTumor* tumor = paciente->getficha()->gettumor();
			cout << "Tumor - Tamanio: " << tumor->gettamanio() << ", Ubicacion: " << tumor->getubicacion() << endl;
		}
		cout << endl;
	}
}
/*
void cCentro::listarOncologos(){
	int i;
	for (i = 0; i < listaOncologo->getCA(); i++) {
		cOncologo* oncologo = listaOncologo->Buscar(i);
		cout << "Oncologo " << i + 1 << ":" << endl;
		cout << "Nombre: " << oncologo->getnombre() << endl;
		cout << "ID: " << oncologo->getID() << endl;
		cout << endl;
	}
}
*/
void cCentro::listarOncologo() {

	//USAR OSTREAM !!!!!!!!!!!!!!!!
}

