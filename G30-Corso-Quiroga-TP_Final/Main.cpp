#include <iostream>
#include <string>
#include <ctime>
#include "cPaciente.h"

using namespace std;

int main() {

	cPaciente* paciente1 = new cPaciente("Pepe", 12345678, "Masculino", 123455689765, O, 30.00);



	delete paciente1;

	return 0;
}