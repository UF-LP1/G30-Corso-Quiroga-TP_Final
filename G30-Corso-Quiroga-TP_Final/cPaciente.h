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
public:
	cPaciente(string nombre, string sexo, int telefono, eTipoSangre tipoSangre, float salud, int cantTumor);
	~cPaciente();
	string getnombre() { return this->nombre; }
	void setnombre(string nombre);
	string getsexo() { return this->sexo; }
	void setsexo(string sexo);
	int gettelefono() { return this->telefono; }
	void settelefono(int telefono);
	eTipoSangre gettiposangre() { return this->tipoSangre; }
	void settiposangre(eTipoSangre tipoSangre);
	float getsalud() { return this->salud; }
	void setsalud(float salud);
	int getcanttumor() { return this->cantTumor; }
	void setcanttumor(int cantTumor);



};

