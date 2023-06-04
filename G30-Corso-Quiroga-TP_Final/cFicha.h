#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class cFicha
{
private:
	//cTime fecha;
	int acumRadiacion;

public:
	cFicha(int acumRadiacion);
	~cFicha();
	
	int getacumRadiacion() { return this->acumRadiacion; }
	void setacumRadiacion(int acumRadiacion);
};

