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
	//Creo tumores
	cTumor* tumor1 = new cTumor(mediano, cabeza, 40); //por parametro
	cTumor* tumor2 = new cTumor(*tumor1); //por copia
	cTumor* tumor3 = new cTumor(); //por defecto
	cTumor* tumor4 = new cTumor(grande, cuello, 20);
	cTumor* tumor5 = new cTumor(pequenio, ojo, 10);

	
	//estoy insertando los tumores en la lista 
	try { cOncologo::tumores->Insertar(tumor1); }
	catch (exception& e) {
		cout << e.what() << endl;
	}
	
	try { cOncologo::tumores->Insertar(tumor4); }
	catch (exception& e) {
		cout << e.what() << endl;
	}

	try { cOncologo::tumores->Insertar(tumor5); }
	catch (exception& e) {
		cout << e.what() << endl;
	}
	
	
	//Creo un paciente, un centro, un dosimetrista y un oncologo
	cPaciente* paciente1 = new cPaciente("Pepe Gonzalez", 12345678, "Masculino", 123455689765, O, 30.00, 12 / 11 / 20);
	cPaciente* paciente2 = new cPaciente("Agustin Perez", 49392939, "Masculino", 94234038943,A, 70.00, 23 / 12 / 21);
	cPaciente* paciente3 = new cPaciente("Julieta Rodriguez", 40932493, "Femenino", 8765434567, AB, 10.00, 31 / 10 / 22);
	
	cCentro* centro = new cCentro();
	cDosimetrista* dosimetrista = new cDosimetrista();
	cOncologo* oncologo1 = new cOncologo("Jose Maria Favaloro", 001);
	cOncologo* oncologo2 = new cOncologo("Isabel Garcia", 002);
	
	
	//Creo las terapias
	
	cBraquiterapia* braquiterapia = new cBraquiterapia();
	cRadioterapiaHaz* radioterapiahaz = new cRadioterapiaHaz();
	cRadioterapiaSistemica* radioterapiasistemica = new cRadioterapiaSistemica();
	
	//Agrego en las listas
	centro->agregarPaciente(paciente1);
	centro->agregarPaciente(paciente2);
	centro->agregarPaciente(paciente3);
	

	centro->agregarOncologo(oncologo1);
	centro->agregarOncologo(oncologo2);
	centro->agregarDosimetrista(dosimetrista);
	
	try {
		centro->crearFicha(paciente1);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	try {
		centro->crearFicha(paciente2);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	try {
		centro->crearFicha(paciente3);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	
	
	
	centro->tratarPaciente(paciente1);
	centro->tratarPaciente(paciente2);
	centro->tratarPaciente(paciente3);

	

	centro->buscarPacienteTyC(braquiterapia, cabeza);
	centro->buscarPacienteTyC(radioterapiahaz, cuello);
	centro->buscarPacienteTyC(radioterapiasistemica, tiroides);

	centro->listarPacientes();


	
	centro->eliminarPaciente(paciente1);
	centro->eliminarPaciente(paciente2);
	centro->eliminarPaciente(paciente3);
	centro->eliminarDosimetrista(dosimetrista);
	centro->eliminarOncologo(oncologo1);
	centro->eliminarOncologo(oncologo2);

	delete centro;

	return 0;

}