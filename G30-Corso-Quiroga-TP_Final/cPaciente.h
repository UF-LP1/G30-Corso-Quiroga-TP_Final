#pragma once
#include <iostream>
#include <string>
#include "eTipoSangre.h"
#include "cLista.h"
#include "cTumor.h"
#include "cFicha.h"

using namespace std;
class cFicha;
class cTumor;

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
	cFicha* ficha;
public:
	cPaciente(string nombre, int DNI, string sexo, int telefono, eTipoSangre tipoSangre, float salud);
	~cPaciente();
	string getnombre() { return this->nombre; }
	void setnombre(string nombre);

	int getDNI() { return this->DNI; }
	void setDNI(int DNI);

	string getsexo() { return this->sexo; }
	void setsexo(string sexo);

	int gettelefono() { return this->telefono; }
	void settelefono(int telefono);

	eTipoSangre gettiposangre() { return this->tipoSangre; }
	void settiposangre(eTipoSangre tipoSangre);

	float getsalud() { return this->salud; }
	void setsalud(float salud);

	cFicha* getficha() { return this->ficha; }
	void setficha(cFicha* ficha);

	int getcantTumor();
	void agregarTumor(cTumor* tumor);
	void eliminarTumor(cTumor* tumor);
	cTumor* quitarTumor(cTumor* tumor);
};

//implementar la clase tumor
// implementar la clas