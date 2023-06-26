#include "cOncologo.h"

cOncologo::cOncologo(string nombre, int ID) {
	this->nombre = nombre;
	this->ID = ID;
}

cOncologo::~cOncologo() {}

int cOncologo::suministrarDosis() { 
	int t= terapia->getTipoTerapia();
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
} 
/*
void cOncologo::frecuencia() { //FALTA HACER ESTO
	
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

	i = rand() % 0 + 3;
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