#include "cOncologo.h"

cOncologo::cOncologo(string nombre, int ID) {
	this->nombre = nombre;
	this->ID = ID;
}

cOncologo::~cOncologo() {}

cLista<cTumor>* cOncologo::encontrarTumores(cPaciente* paciente){
	int i = rand () % 0 + 3;
	cLista <cTumor>* ToR = new cLista <cTumor>(i);
	if (i > 0) {
		int j;
		//hacer un for y adentro poner esto:
		// crear un random y luego:
		//cOncologo::tumores->Buscar() //ahi dentro poner el nombre del random
	}
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