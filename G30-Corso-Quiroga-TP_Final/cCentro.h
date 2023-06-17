#pragma once
#include <iostream>
#include <string>
#include "cLista.h"
#include "cPaciente.h"
#include "cOncologo.h"
#include "cTerapia.h"
#include "eUbicacion.h"

using namespace std;

class cCentro
{
private:
	const int maxPaciente = 100;
	const int maxOncologo = 100;
	cLista <cPaciente>* listaPaciente;
	cLista <cOncologo>* listaOncologo;

public:

	cCentro();
	~cCentro();

	void agregarPaciente(cPaciente* paciente);
	void eliminarPaciente(cPaciente* paciente);

	void agregarOncologo(cOncologo* oncologo);
	void eliminarOncologo(cOncologo* oncologo);

	void crearFicha(cPaciente* paciente);

	cLista <cPaciente>* buscarPacienteTyC(cTerapia* terapia, eUbicacion ubicacion);
	
	void listarPacientes();
	//void listarOncologos();
};

