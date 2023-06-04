#pragma once
#include <iostream>
#include <string>
#include "eTipoSangre.h"
#include "cLista.h"
#include "cTumor.h"

using namespace std;

class cPaciente{
private:
	string nombre;
	int DNI;
	//ctime fechaNac;
	string sexo;
	int telefono;
	eTipoSangre tipoSangre;
	float salud;
	cLista <cTumor>* listaTumor;
public:
	cPaciente(string nombre, int DNI, string sexo, int telefono, eTipoSangre tipoSangre, float salud);
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


	int getcantTumor();
	void agregarTumor(cTumor* tumor);
	void eliminarTumor(cTumor* tumor);
};

//implementar la clase tumor
// implementar la clas