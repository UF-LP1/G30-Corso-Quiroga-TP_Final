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
	try {
		cOncologo::tumores = new cLista<cTumor>(4);
		cTumor* tumor1 = new cTumor(mediano, cabeza, 40); //por parametro
		cTumor* tumor2 = new cTumor(*tumor1); //por copia
		cTumor* tumor3 = new cTumor(); //por defecto
		cTumor* tumor4 = new cTumor(grande, cuello, 20);

		cOncologo::tumores->Insertar(tumor1); //estoy insertando un tumor en la lista 
		cOncologo::tumores->Insertar(tumor3);
		cOncologo::tumores->Insertar(tumor4);

		cPaciente* paciente1 = new cPaciente("Pepe", 12345678, "Masculino", 123455689765, O, 30.00, 12 / 11 / 20);
		cCentro* centro = new cCentro();
		cDosimetrista* dosimetrista = new cDosimetrista();
		cOncologo* oncologo1 = new cOncologo("Jose Maria", 001);

		cBraquiterapia* braquiterapia = new cBraquiterapia();
		cRadioterapiaHaz* radioterapiahaz = new cRadioterapiaHaz();
		cRadioterapiaSistemica* radioterapiasistemica = new cRadioterapiaSistemica();

		centro->agregarPaciente(paciente1);
		centro->agregarOncologo(oncologo1);
		centro->agregarDosimetrista(dosimetrista);
		centro->crearFicha(paciente1);

		cout << "Estoy creando una ficha del paciente" << endl;

		centro->tratarPaciente(paciente1);

		cout << "Trato al paciente con su respectiva terapia" << endl;

		centro->buscarPacienteTyC(braquiterapia, cabeza);
		centro->buscarPacienteTyC(radioterapiahaz, cuello);
		centro->buscarPacienteTyC(radioterapiasistemica, tiroides);

		centro->listarPacientes();

		delete centro;
	}
	catch (exception& e) {
		cout << "Error" << e.what() << endl;
		return 0;
	}
		return 0;

}