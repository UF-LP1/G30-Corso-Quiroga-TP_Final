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
	*listaPaciente + (paciente);
	/*
	try { this->listaPaciente->Insertar(paciente); }
	catch (exception & e) {
		cout << e.what() << endl;
	} 
	*/
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
	// Creo una nueva lista para almacenar los pacientes que cumplen con los criterios de búsqueda
	cLista<cPaciente>* ToR = new cLista<cPaciente>(this->listaPaciente->getCA());

	int i;
	for (i = 0; i < this->listaPaciente->getCA(); i++) {
		// Obtengo el paciente en la posición i
		cPaciente* paciente = this->listaPaciente->Buscar(i);

		// Defino los diferentes tipos de terapia
		eTipoTerapia tipoTerapiaRadioterapiaHaz = eTipoTerapia::radioterapiaHaz;
		eTipoTerapia tipoTerapiaBraquiterapia = eTipoTerapia::braquiterapia;
		eTipoTerapia tipoTerapiaRadioterapiaSistemica = eTipoTerapia::radioterapiaSistemica;

		// Verifico si el tipo de terapia del paciente coincide con radioterapiaHaz
		if (paciente->getficha()->getterapia()->getTipoTerapia(tipoTerapiaRadioterapiaHaz) == terapia->getTipoTerapia(tipoTerapiaRadioterapiaHaz)) {
			// Si coincide, verifico la ubicación del tumor del paciente
			if (paciente->getficha()->gettumor()->getubicacion() == ubicacion) {
				try {
					// Inserto el paciente en la lista ToR
					ToR->Insertar(paciente);
				}
				// Si se produce una excepción al intentar insertar el paciente, muestro el mensaje de error
				catch (exception& e) { //capturo la excepción y la almacento en una variable e
					cout << e.what() << endl; //devuelvo una cadena de caracteres que describe la excepción
				}
			}
		}

		// Verificar si el tipo de terapia del paciente coincide con braquiterapia
		if (paciente->getficha()->getterapia()->getTipoTerapia(tipoTerapiaBraquiterapia) == terapia->getTipoTerapia(tipoTerapiaBraquiterapia)) {
			// Si coincide, verificar la ubicación del tumor del paciente
			if (paciente->getficha()->gettumor()->getubicacion() == ubicacion) {
				try {
					// Insertar el paciente en la lista ToR
					ToR->Insertar(paciente);
				}
				catch (exception& e) {
					cout << e.what() << endl;
				}
			}
		}

		// Verificar si el tipo de terapia del paciente coincide con radioterapiaSistemica
		if (paciente->getficha()->getterapia()->getTipoTerapia(tipoTerapiaRadioterapiaSistemica) == terapia->getTipoTerapia(tipoTerapiaRadioterapiaSistemica)) {
			// Si coincide, verificar la ubicación del tumor del paciente
			if (paciente->getficha()->gettumor()->getubicacion() == ubicacion) {
				try {
					// Insertar el paciente en la lista ToR
					ToR->Insertar(paciente);
				}
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
/*
void cCentro::operator+(cDosimetrista* dosimetrista){
	if ((*listaDosimetrista) == dosimetrista) {
		throw runtime_error("El dosimetrista ya existe en la lista."); //uso el runtime_error para indicar errores en tiempo de ejecución
	}
	listaDosimetrista->Insertar(dosimetrista);
}

void cCentro::operator-(cDosimetrista* dosimetrista) {
	int posicion = (*listaDosimetrista) == dosimetrista;
	if (posicion != -1) {
		listaDosimetrista->QuitarPos(posicion);
		delete dosimetrista;
	}
}
*/
void cCentro::agregarDosimetrista(cDosimetrista* dosimetrista) {
	//this->listaDosimetrista + dosimetrista;
	
	try { this->listaDosimetrista->Insertar(dosimetrista); }
	catch (exception& e) {
		cout << e.what() << endl;
	}

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