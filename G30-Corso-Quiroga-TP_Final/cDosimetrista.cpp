#include "cDosimetrista.h"

cDosimetrista::cDosimetrista(int tipoTerapia) {
	this->tipoTerapia = tipoTerapia;
}
cDosimetrista::~cDosimetrista() {}

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
}

int cDosimetrista::determinarTipoTerapia(cTumor* tumor) {//FALTA HACER ESTO
	int i = 0;

	switch (tumor->getubicacion()) {
		case (cabeza, cuello, mama, utero, ojo):
			 i = rand() % 0 + 1;
			 if(i == 0)
				 tipoTerapia = 1;
			 else
				 tipoTerapia = 2;
			 break;
		case (tiroides, prostata):
			i = rand() % 0 + 1;
			if (i == 0)
				tipoTerapia = 1;
			else
				tipoTerapia = 3;
			break;
		case (pulmon, intestino):
			tipoTerapia = 1;
			break;
	}
	return tipoTerapia;
}

