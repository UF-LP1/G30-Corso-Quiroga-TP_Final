#include "cCentro.h"


cCentro::cCentro() {

	this->listaPaciente = new cLista<cPaciente>(maxPaciente);
	this->listaOncologo = new cLista<cOncologo>(maxOncologo);
	this->listaDosimetrista = new cLista<cDosimetrista>(maxDosimetrista);
	
}
cCentro::~cCentro() {
	
	delete listaDosimetrista;
	delete listaPaciente;
	delete listaPaciente;
}

void cCentro::agregarPaciente(cPaciente* paciente) {
	
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

cFicha* cCentro::crearFicha(cPaciente* paciente) {

	int pos = listaPaciente->BuscarAtPos(paciente); //chequeo que el paciente este
	if (pos == -1) {
		throw runtime_error("El paciente no esta registrado en el centro.");
	}
	else {
		cTerapia* terapia = NULL;
		int i = rand() % listaOncologo->getCA();
		cOncologo* oncologo = listaOncologo->Buscar(i);
		cLista<cTumor>* tumores = oncologo->encontrarTumores(paciente);
		if (tumores->getCA() > 0) {
			i = rand() % listaDosimetrista->getCA();
			cDosimetrista* dosimetrista = listaDosimetrista->Buscar(i);
			terapia = dosimetrista->determinarTipoTerapia(tumores);
		}

		cFicha* ficha = new cFicha(terapia, paciente, oncologo, 12 / 12 / 20);

		return ficha;
	}

}



cLista <cPaciente>* cCentro::buscarPacienteTyC(cTerapia* terapia, eUbicacion ubicacion) {
	cLista <cPaciente>* ToR = new cLista <cPaciente>(this->listaPaciente->getCA());
	int i;
	for (i = 0; i < this->listaPaciente->getCA(); i++) {
		cPaciente* paciente = this->listaPaciente->Buscar(i);  //devuelve el paciente en la pos i
		if (paciente->getficha() != NULL && paciente->getficha()->getterapia()->getTipoTerapia() == terapia->getTipoTerapia()) {
			if (paciente->getficha()->gettumor()->getubicacion() == ubicacion) {
				try { ToR->Insertar(paciente); }
				catch (exception& e) {
					cout << e.what() << endl;
				}


			}
		}

	}
	return ToR;
}

void cCentro::listarPacientes() { //verifico si el paciente tiene una ficha, si es así, puedo obtener el tumor y su ubicacion y listarlo con el resto de datos
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

void cCentro::listarOncologo() {

	//ARREGLAR!!!!!!!!!!!!!!!
	/*int i;
	for (i = 0; i < listaOncologo->getCA(); i++) {
		cOncologo* oncologo = listaOncologo->Buscar(i);
		cout << "Oncologo " << i + 1 << ":" << endl;
		cout << "Nombre: " << oncologo->getnombre() << endl;
		cout << "ID: " << oncologo->getID() << endl;
		cout << endl;
	}*/
}



void cCentro::agregarDosimetrista(cDosimetrista* dosimetrista) {

	this->listaDosimetrista->operator+(dosimetrista);
	/*
	try { this->listaDosimetrista->Insertar(dosimetrista); }
	catch (exception& e) {
		cout << e.what() << endl;
	}*/

}
void cCentro::eliminarDosimetrista(cDosimetrista* dosimetrista) {
	int i = this->listaDosimetrista->BuscarAtPos(dosimetrista);
	this->listaDosimetrista->operator-(dosimetrista); //ARREGLAR!!!!!!!!!!!!!!!!!
	/*
	int pos = listaDosimetrista->BuscarAtPos(dosimetrista);
	if (pos != -1) {
		cDosimetrista* eliminarDosimetrista = listaDosimetrista->QuitarPos(pos);
		delete eliminarDosimetrista;
	}*/

}

void cCentro::tratarPaciente(cPaciente* paciente) {
	cFicha* ficha = paciente->getficha();
	if (ficha->getsesion() < ficha->getterapia()->getcantsesion()) {
		try {
			ficha->getterapia()->AplicarTerapia(paciente);
			ficha->setcantsesion(ficha->getsesion() + 1);
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
}