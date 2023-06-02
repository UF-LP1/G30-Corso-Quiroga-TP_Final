#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "eTipoSangre.h"

using namespace std;

class cPaciente{
private:
	string nombre;
	const int DNI;
	//ctime fechaNac;
	string sexo;
	int telefono;
	eTipoSangre tipoSangre;
	float salud;
	int cantTumor;
};

