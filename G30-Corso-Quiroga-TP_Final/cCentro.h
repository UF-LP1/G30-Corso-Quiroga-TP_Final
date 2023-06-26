#pragma once
#ifndef _CCENTRO_H
#define _CCENTRO_H
#include <iostream>
#include <string>
#include "cLista.h"
#include "cPaciente.h"
#include "cOncologo.h"
#include "cTerapia.h"
#include "eUbicacion.h"
#include "cDosimetrista.h"

using namespace std;
class cPaciente;
class cOncologo;
class cTerapia;
class cDosimetrista;

class cCentro
{
private:
	const int maxPaciente = 100;
	const int maxOncologo = 100;
	const int maxDosimetrista = 100;
	
	cLista <cPaciente>* listaPaciente;
	cLista <cOncologo>* listaOncologo;
	cLista<cDosimetrista>* listaDosimetrista;

public:

	cCentro();
	~cCentro();
	
	void agregarPaciente(cPaciente* paciente);
	void eliminarPaciente(cPaciente* paciente);

	void agregarOncologo(cOncologo* oncologo);
	void eliminarOncologo(cOncologo* oncologo);

	void agregarDosimetrista(cDosimetrista* dosimetrista);
	void eliminarDosimetrista(cDosimetrista* dosimetrista);

	void tratarPaciente(cPaciente* paciente);

	cFicha* crearFicha(cPaciente* paciente);

	cLista <cPaciente>* buscarPacienteTyC(cTerapia* terapia, eUbicacion ubicacion);
	
	void listarPacientes();
	
	void listarOncologo();
};
#endif
