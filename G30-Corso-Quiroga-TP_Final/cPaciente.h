#ifndef _CPACIENTE_H
#define _CPACIENTE_H

class cFicha;

#include <iostream>
#include <string>
#include "eTipoSangre.h"
#include "cLista.h"
#include "cFicha.h"

using namespace std;


class cPaciente {
private:
	string nombre;
	int DNI;
	time_t fechaNac;
	string sexo;
	int telefono;
	eTipoSangre tipoSangre;
	float salud;
	cFicha* ficha;
	bool curado;
public:
	cPaciente(string nombre, int DNI, string sexo, int telefono, eTipoSangre tipoSangre, float salud, time_t fechaNac);
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

	string to_string();
	friend ostream& operator<<(ostream& out, cPaciente& paciente); //tengo acceso directo a los miembros privados y protegidos de la clase cPaciente
	void setCurado(bool curado) { this->curado = curado; }
	bool getCurado() { return this->curado; }

};
#endif
