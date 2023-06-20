#include "cDosimetrista.h"

cDosimetrista::cDosimetrista(int tipoTerapia) {
	this->tipoTerapia = tipoTerapia;
}
cDosimetrista::~cDosimetrista() {}
/*
int cDosimetrista::calcularDosisTotal() { //FALTA HACER ESTO
	int tipo = 0, dosisTotal = 0;
	tipo = this->terapia->getTipoTerapia();
	
	if (tipo == 1) 
		dosisTotal = rand() % 1 + 10; // 1-10 Gy
	else if(tipo == 2)
		dosisTotal = rand() % 100 + 160; // 100-160 Gy
	else if (tipo == 3)
		dosisTotal = rand() % 20 + 40; // 20-40 Gy

	return dosisTotal;
}*/

cTerapia* cDosimetrista::determinarTipoTerapia(cLista<cTumor>* tumores) {//FALTA HACER ESTO
	int i = 0;
	cTerapia* tipoTerapia = NULL;
	if (tumores->getCA() == 1) {
		cTumor* tumor = tumores->Buscar(0);
	switch (tumor->getubicacion()) {
		case (cabeza, cuello, mama, utero, ojo):
			 i = rand() % 0 + 1;
			 if(i == 0)
				 tipoTerapia = new cRadioterapiaHaz();  
			 else
				 tipoTerapia = new cBraquiterapia();
			 break;
		case (tiroides, prostata):
			i = rand() % 0 + 1;
			if (i == 0)
				tipoTerapia = new cRadioterapiaHaz();
			else
				tipoTerapia = new cRadioterapiaSistemica();
			break;
		case (pulmon, intestino):
			tipoTerapia = new cRadioterapiaHaz();
			break;
	}

	}
	else {
		tipoTerapia = new cRadioterapiaHaz(); 
	}
	
	return tipoTerapia;
}

//1 = HAZ
//2 = Braqui
//3 = Sistemica