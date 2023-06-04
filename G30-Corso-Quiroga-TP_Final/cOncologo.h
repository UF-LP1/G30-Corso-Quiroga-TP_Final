#pragma once
#include <iostream>
#include <string>


using namespace std;

class cOncologo{

private:
	string nombre;
	int ID;
public:
	cOncologo(string nombre, int ID);
	~cOncologo();
	void suministrarDosis();  //CORREGIR
	void frecuencia(); //CORREGIR

	string getnombre() { return this->nombre; }
	void setnombre(string nombre);
	int getID() { return this->ID; }
	void setID(int ID);
};

