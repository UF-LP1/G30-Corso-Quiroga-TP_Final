﻿#include "cCentro.h"


cCentro::cCentro() {

	this->listaPaciente = new cLista<cPaciente>(maxPaciente);
	this->listaOncologo = new cLista<cOncologo>(maxOncologo);
	this->listaDosimetrista = new cLista<cDosimetrista>(maxDosimetrista);

}
cCentro::~cCentro() {
	
	delete listaDosimetrista;
	delete listaPaciente;
	delete listaOncologo;
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

void cCentro::eliminarPaciente(cPaciente* paciente) { //si encuentro la posicion del paciente en la lista lo elimino
	int pos = listaPaciente->BuscarAtPos(paciente);
	if (pos != -1) {
		cPaciente* eliminarPaciente = listaPaciente->QuitarPos(pos);
		delete eliminarPaciente;
	}
}

void cCentro::agregarOncologo(cOncologo* oncologo) {

	try { this->listaOncologo->Insertar(oncologo); }
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

void cCentro::eliminarOncologo(cOncologo* oncologo) { //si encuentro la posicion del oncologo en la lista lo elimino
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
		ficha->setFichaTumores(tumores);
		paciente->setficha(ficha);
		
		return ficha;
	}
	
	

}



cLista <cPaciente>* cCentro::buscarPacienteTyC(cTerapia* terapia, eUbicacion ubicacion) {
	// Creo una nueva lista para almacenar los pacientes que cumplen con los criterios de b�squeda
	cLista<cPaciente>* ToR = new cLista<cPaciente>(this->listaPaciente->getCA());

	int i;
	for (i = 0; i < this->listaPaciente->getCA(); i++) {
		// Obtengo el paciente en la posici�n i
		cPaciente* paciente = this->listaPaciente->Buscar(i);
		cFicha* ficha = paciente->getficha();
		// Defino los diferentes tipos de terapia
		eTipoTerapia tipoTerapiaRadioterapiaHaz = eTipoTerapia::radioterapiaHaz;
		eTipoTerapia tipoTerapiaBraquiterapia = eTipoTerapia::braquiterapia;
		eTipoTerapia tipoTerapiaRadioterapiaSistemica = eTipoTerapia::radioterapiaSistemica;

		// Verifico si el tipo de terapia del paciente coincide con radioterapiaHaz
		if (dynamic_cast<cRadioterapiaHaz*>(ficha->getterapia()) != nullptr) {
			// Si coincide, verifico la ubicaci�n del tumor del paciente
			bool found = false;
			int j = 0;
			while (!found && j < paciente->getficha()->getTumores()->getCA()) {
				cTumor* tumor = paciente->getficha()->getTumores()->Buscar(j);
				if (tumor->getubicacion() == ubicacion) {
					found = true;
					try {
						// Inserto el paciente en la lista ToR
						ToR->Insertar(paciente);
					}
					catch (exception& e) { //capturo la excepci�n y la almacento en una variable e
						cout << e.what() << endl; //devuelvo una cadena de caracteres que describe la excepci�n
					}
				}
				else
					j++;

			}


			// Si se produce una excepci�n al intentar insertar el paciente, muestro el mensaje de error

		}


		// Verificar si el tipo de terapia del paciente coincide con braquiterapia
		if ((dynamic_cast<cRadioterapiaSistemica*>(ficha->getterapia()) != nullptr)) {
			// Si coincide, verifico la ubicaci�n del tumor del paciente
			bool found = false;
			int j = 0;
			while (!found && j < paciente->getficha()->getTumores()->getCA()) {
				cTumor* tumor = paciente->getficha()->getTumores()->Buscar(j);
				if (tumor->getubicacion() == ubicacion) {
					found = true;
					try {
						// Inserto el paciente en la lista ToR
						ToR->Insertar(paciente);
					}
					catch (exception& e) { //capturo la excepci�n y la almacento en una variable e
						cout << e.what() << endl; //devuelvo una cadena de caracteres que describe la excepci�n
					}
				}
				else
					j++;

			}


			// Si se produce una excepci�n al intentar insertar el paciente, muestro el mensaje de error

		}


		// Verificar si el tipo de terapia del paciente coincide con braquiterapia
		if ((dynamic_cast<cBraquiterapia*>(ficha->getterapia()) != nullptr)) {
			// Si coincide, verifico la ubicaci�n del tumor del paciente
			bool found = false;
			int j = 0;
			while (!found && j < paciente->getficha()->getTumores()->getCA()) {
				cTumor* tumor = paciente->getficha()->getTumores()->Buscar(j);
				if (tumor->getubicacion() == ubicacion) {
					found = true;
					try {
						// Inserto el paciente en la lista ToR
						ToR->Insertar(paciente);
					}
					catch (exception& e) { //capturo la excepci�n y la almacento en una variable e
						cout << e.what() << endl; //devuelvo una cadena de caracteres que describe la excepci�n
					}
				}
				else
					j++;

			}


			// Si se produce una excepci�n al intentar insertar el paciente, muestro el mensaje de error

		}


	}

	return ToR;
}

void cCentro::listarPacientes() { //verifico si el paciente tiene una ficha, si es as�, puedo obtener el tumor y su ubicacion y listarlo con el resto de datos
	cout << "LISTADO DE PACIENTES DEL CENTRO: " << endl << endl;
	int i;
	for (i = 0; i < listaPaciente->getCA(); i++) {
		cPaciente* paciente = listaPaciente->Buscar(i);
		cOncologo* oncologo = paciente->getficha()->getoncologo();
		cout << "Paciente " << i + 1 << ":" << endl;
		cout << endl;
		cout << "- Nombre: " << paciente->getnombre() << endl;
		cout << "- DNI: " << paciente->getDNI() << endl;
		//cout << "Oncologo " << i + 1 << ":" << endl;
		cout << "- Nombre Oncologo: " << oncologo->getnombre() << endl;
		cout << "- ID Oncologo : " << oncologo->getID() << endl;
		cout << endl;
		if (paciente->getficha() != NULL) { //si no tiene una ficha entonces no imprime estos ultimos datos
			cLista<cTumor>* tumores = paciente->getficha()->getTumores();
			int i;
			for (i = 0; i < tumores->getCA(); i++) {
				cTumor* tumor = tumores->Buscar(i);
				cout << "Tumor - Tamanio: " << tumor->gettamanio() << ", Ubicacion: " << tumor->getubicacion() << endl;

			}
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
		throw runtime_error("El dosimetrista ya existe en la lista."); //uso el runtime_error para indicar errores en tiempo de ejecuci�n
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
	int i = listaDosimetrista->getCA();
	*listaDosimetrista + (dosimetrista);
	
}

void cCentro::eliminarDosimetrista(cDosimetrista* dosimetrista) {
	*listaDosimetrista - (dosimetrista);
	
}

void cCentro::tratarPaciente(cPaciente* paciente) {
	cFicha* ficha = paciente->getficha();
	if (ficha->getcantTumor() > 0 && !paciente->getCurado() && ficha->getterapia() != NULL) {
		
		int radiacion;
		radiacion = ficha->getterapia()->AplicarTerapia(ficha->getTumores());


		if (dynamic_cast<cRadioterapiaHaz*>(ficha->getterapia()) != nullptr) {
			if (ficha->getacumRadiacion() + radiacion > 10)
				throw new exception("No se puede continuar con la terapia");


		}


		if (dynamic_cast<cBraquiterapia*>(ficha->getterapia()) != nullptr) {
			if (ficha->getacumRadiacion() + radiacion > 160)
				throw new exception("No se puede continuar con la terapia");


		}

		if (dynamic_cast<cRadioterapiaSistemica*>(ficha->getterapia()) != nullptr) {
			if (ficha->getacumRadiacion() + radiacion > 40)
				throw new exception("No se puede continuar con la terapia");


		}
		ficha->aplicarRadiacion(radiacion);
		ficha->setcantsesion(ficha->getsesion());



	}
	//Chequeo si le tengo que dar el alta
	this->darAlta(ficha);
}

void cCentro::darAlta(cFicha* paciente) {
	//Se asume que el primer oncologo evalua al paciente
	cOncologo* oncologo = this->listaOncologo->Buscar(0);



}

cLista <cPaciente>* cCentro::buscarPacienteLimite() {
	cLista<cPaciente>* _toR = new cLista<cPaciente>(this->listaPaciente->getCA());
	int i;
	for (i = 0; i < this->listaPaciente->getCA(); i++) {
		cPaciente* _paciente = this->listaPaciente->Buscar(i);
		//Si encuentra algun tumor con radicion limite me lo inserta-...
		if (_paciente->getficha()->encontrarRadicionLimite())
			_toR->Insertar(_paciente);
	}
	return _toR;
}
