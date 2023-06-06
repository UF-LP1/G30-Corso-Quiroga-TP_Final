#include <iostream>
#include <string>
#include <ctime>
#include "cPaciente.h"
#include "cCentro.h"

using namespace std;

int main() {

	cPaciente* paciente1 = new cPaciente("Pepe", 12345678, "Masculino", 123455689765, O, 30.00);
	cCentro* centro = new cCentro();

	centro->agregarPaciente(paciente1);


	delete paciente1;

	return 0;
}