#include <iostream>
#include <string>
#include <ctime>

#include "cPaciente.h"
#include "cCentro.h"
#include "cOncologo.h"
#include "cDosimetrista.h"
#include "cTumor.h"
#include "cFicha.h"
#include "cBraquiterapia.h"
#include "cRadioterapiaHaz.h"
#include "cRadioterapiaSistemica.h"


using namespace std;

int main() {
	cOncologo::tumores = new cLista<cTumor>(4);
	//en buscartumor asignar un random y leer de la lista
	cTumor* tumor1 = new cTumor(mediano, cabeza, 40); //por parametro
	cTumor* tumor2 = new cTumor(*tumor1); //por copia
	cTumor* tumor3 = new cTumor(); //por defecto
	cTumor* tumor4 = new cTumor(grande, cuello, 20);
	cOncologo::tumores->Insertar(tumor1); //estoy insertando un tumor en la lista 
	cOncologo::tumores->Insertar(tumor3);
	cOncologo::tumores->Insertar(tumor4);

	cPaciente* paciente1 = new cPaciente("Pepe", 12345678, "Masculino", 123455689765, O, 30.00, 12/11/20);
	cCentro* centro = new cCentro();
	cDosimetrista* dosimetrista = new cDosimetrista();
	cOncologo* oncologo1 = new cOncologo("Jose Maria", 001);

	centro->agregarPaciente(paciente1);
	centro->agregarOncologo(oncologo1);
	centro->agregarDosimetrista(dosimetrista); 
	centro->crearFicha(paciente1);

	centro->tratarPaciente(paciente1);
	//centro->buscarPacienteTyC();
	
	delete centro;

	return 0;
}