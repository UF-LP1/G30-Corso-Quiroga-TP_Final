#pragma once
#ifndef _CFICHA_H
#define _CFICHA_H
#include <iostream>
#include <string>
#include <ctime>
#include "cTerapia.h"
#include "cPaciente.h"
#include "cOncologo.h"
#include "cTumor.h"

using namespace std;
class cPaciente;
class cTerapia;
class cOncologo;
class cTumor;

class cFicha
{
private:
	time_t fecha;
	float acumRadiacion;
	int sesionPracticada;
	int cantsesion;
	cTerapia* terapia; 
	cPaciente* paciente; 
	cOncologo* oncologo; 
	cTumor* tumor;
	cLista <cTumor>* listaTumor;

public:
	cFicha(cTerapia* terapia, cPaciente* paciente, cOncologo* oncologo, time_t fecha);
	cFicha(cPaciente* paciente);
	~cFicha();

	int getacumRadiacion() { return this->acumRadiacion; }
	void setacumRadiacion(float acumRadiacion);

	int getsesion() { return this->sesionPracticada; }
	void setsesion(int sesionesPracticadas);

	int getcantsesion() { return this->cantsesion; }
	void setcantsesion(int cantsesiones);
	
	cTerapia* getterapia() { return this->terapia; }
	void setterapia(cTerapia* terapia);

	string to_string();

	cPaciente* getpaciente() { return this->paciente; }
	void setpaciente(cPaciente* paciente);

	cOncologo* getoncologo() { return this->oncologo; }
	void setoncologo(cOncologo* oncologo);

	cTumor* gettumor() { return this->tumor; }
	void settumor(cTumor* tumor);
	
	void aplicarRadiacion(float radiacion);

	int getcantTumor();
	void agregarTumor(cTumor* tumor);
	void eliminarTumor(cTumor* tumor);
	cTumor* quitarTumor(cTumor* tumor);
};
#endif