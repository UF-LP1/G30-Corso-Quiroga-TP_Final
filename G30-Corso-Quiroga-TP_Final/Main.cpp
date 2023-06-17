#include <iostream>
#include <string>
#include <ctime>
#include "cPaciente.h"
#include "cCentro.h"
#include "cOncologo.h"

using namespace std;

int main() {
	cOncologo::tumores = new cLista<cTumor>(4);
	//crear 4 tumores 
	//insertarlos en la lista
	//en buscartumor asignar un random y leer de la lista
	cOncologo::tumores->Insertar(NULL); //estoy insertando un tumor en la lista (poner otro numero)
	cPaciente* paciente1 = new cPaciente("Pepe", 12345678, "Masculino", 123455689765, O, 30.00);
	cCentro* centro = new cCentro();

	centro->agregarPaciente(paciente1);


	delete paciente1;

	return 0;
}