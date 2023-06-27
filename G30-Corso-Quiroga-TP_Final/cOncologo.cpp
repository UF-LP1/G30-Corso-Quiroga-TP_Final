#include "cOncologo.h"

cOncologo::cOncologo(string nombre, int ID) {
	this->nombre = nombre;
	this->ID = ID;
}

cOncologo::~cOncologo() {}

int cOncologo::suministrarDosis() { 
	eTipoTerapia t;

	if (t == eTipoTerapia::radioterapiaHaz) {
		t = terapia->getTipoTerapia(eTipoTerapia::radioterapiaHaz);
	}
	else if (t == eTipoTerapia::braquiterapia) {
		t = terapia->getTipoTerapia(eTipoTerapia::braquiterapia);
	}
	else if (t == eTipoTerapia::radioterapiaSistemica) {
		t = terapia->getTipoTerapia(eTipoTerapia::radioterapiaSistemica);
	} // Obtengo el tipo de terapia

	int dosis = 0, aux = 0;

	if (t == eTipoTerapia::radioterapiaHaz) { // Si el tipo de terapia es radioterapiaHaz
		aux = rand() % 2; // Genero un número aleatorio entre 0 y 1
		if (aux == 0)
			dosis = 1; // Asigno dosis de 1 Gy
		else
			dosis = 2; // Asigno dosis de 2 Gy
	}
	else if (t == eTipoTerapia::braquiterapia) { // Si el tipo de terapia es braquiterapia
		aux = rand() % 3; // Genero un número aleatorio entre 0 y 2
		if (aux == 0)
			dosis = 4; // Asigno dosis de 4 Gy
		else if (aux == 1)
			dosis = 6; // Asigno dosis de 6 Gy
		else
			dosis = 8; // Asigno dosis de 8 Gy
	}
	else if (t == eTipoTerapia::radioterapiaSistemica) { // Si el tipo de terapia es radioterapiaSistemica
		aux = rand() % 3; // Genero un número aleatorio entre 0 y 2
		if (aux == 0)
			dosis = 2; // Asigno dosis de 2 Gy
		else if (aux == 1)
			dosis = 4; // Asigno dosis de 4 Gy
		else
			dosis = 6; // Asigno dosis de 6 Gy
	}
	return dosis; // Devuelvo la dosis calculada
	/*
	int t= terapia
		->getTipoTerapia();
	int dosis = 0, aux = 0;
	aux = rand() % 0 + 1;
	if (t == 1) {// 1 a 2 Gy
		if (aux == 0)
			dosis = 1;
		else
			dosis = 2;
	}
	else if (t == 2) {// 6 a 8 Gy
		if (aux == 0)
			dosis = 6;
		else
			dosis = 8;
		
	}
	else if (t == 3) {//2 a 4 Gy
		if (aux == 0)
			dosis = 2;
		else
			dosis = 4;
		
	}
	return dosis;
	*/
}
string cOncologo::to_string(){		
		string result = "Paciente ";
		result += this->nombre;
		result += ", con ID: ";
		return result;
}


/*
void cOncologo::frecuencia() { /
	
	int dosisTotal = this->dosimetrista->calcularDosisTotal();
	int dosis = this->suministrarDosis();

	float frec = dosisTotal / dosis;
}*/

cLista<cTumor>* cOncologo::encontrarTumores(cPaciente* paciente) {
	cLista<cTumor>* listaClonada = new cLista<cTumor>(cOncologo::tumores->getCA());
	int i;
	for (i = 0; i < cOncologo::tumores->getCA(); i++) {
		try { listaClonada->Insertar(cOncologo::tumores->Buscar(i)); } //clono la lista }
		catch (exception& e) {
			cout << e.what() << endl;
		}

	}

	i = rand() % 3;
	cLista <cTumor>* ToR = new cLista <cTumor>(i);
	if (i > 0) {
		int j;
		for (j = 0; j < i; j++) {
			int k = rand() % listaClonada->getCA();
			try { ToR->Insertar(listaClonada->Buscar(k)); }
			catch (exception& e) {
				cout << e.what() << endl;
			}
			try { listaClonada->Eliminar(k); }
			catch (exception& e) {
				cout << e.what() << endl;
			}

		}

	}
	delete listaClonada;
	return ToR;

}

void cOncologo::setnombre(string nombre)
{
	this->nombre = nombre;
	return;
}

void cOncologo::setID(int ID)
{
	this->ID = ID;
	return;
}