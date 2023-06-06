#pragma once
#include <iostream>
#include <string>

using namespace std;

class cTerapia
{


public:
	cTerapia();
	~cTerapia();
	virtual int getTipoTerapia() = 0;

};

