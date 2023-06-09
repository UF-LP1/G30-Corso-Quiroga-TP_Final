#include "cDosimetrista.h"

cDosimetrista::cDosimetrista() {

}
cDosimetrista::~cDosimetrista() {}
/*
int cDosimetrista::calcularDosisTotal() {
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

cTerapia* cDosimetrista::determinarTipoTerapia(cLista<cTumor>* tumores) {
	int i = 0;
	
	cTerapia* tipoTerapia = NULL;
	eTipoTerapia etipoTerapia;
	
	if (tumores->getCA() == 1) {
		cTumor* tumor = tumores->Buscar(0);
		
		switch (tumor->getubicacion()) {
		case (cabeza, cuello, mama, utero, ojo):
			i = rand() % 0 + 1;
			if (i == 0) {
				tipoTerapia = new cRadioterapiaHaz();
				etipoTerapia = radioterapiaHaz;
			}

			else {
				tipoTerapia = new cBraquiterapia();
				etipoTerapia = braquiterapia;
			}

			break;
		case (tiroides, prostata):
			i = rand() % 0 + 1;
			if (i == 0) {
				tipoTerapia = new cRadioterapiaHaz();
				etipoTerapia = radioterapiaHaz;
			}

			else {
				tipoTerapia = new cRadioterapiaSistemica();
				etipoTerapia = radioterapiaSistemica;
			}

			break;
		case (pulmon, intestino):
		{
			tipoTerapia = new cRadioterapiaHaz();
			etipoTerapia = radioterapiaHaz;
		}

		break;
		}

	}
	else {
		
		tipoTerapia = new cRadioterapiaHaz();
		etipoTerapia = radioterapiaHaz;
	}
	

	return tipoTerapia;
}

//1 = HAZ
//2 = Braqui
//3 = Sistemica