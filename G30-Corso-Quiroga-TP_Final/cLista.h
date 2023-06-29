#pragma once
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

#define TMAX 150

template <class T1> //T1 tipo de lista
class cLista
{
	T1** lista;
	unsigned int ca, t;

public:
	cLista(unsigned int T = TMAX);
	~cLista(void);
	void Insertar(T1* P);

	T1* Quitar(unsigned int pos);

	void Eliminar(int pos);


	T1* Buscar(int pos);

	int BuscarAtPos(T1* pos);

	T1* QuitarPos(unsigned int pos);
	void EliminarenPos(T1* P);
	void Switch(unsigned int pos1, unsigned int pos2);
	int getCA() const { return ca; };
	void operator+(T1* p) { Insertar(p); };
	void operator-(T1* p) { EliminarenPos(p); };
	friend ostream& operator<<(ostream& out, cLista<T1>& Lista);

	int operator==(T1* elemento) const {
		for (int i = 0; i < ca; i++) {
			if (*lista[i] == *elemento) {
				return i;
			}
		}
		return -1;
	}

	T1* operator[](unsigned int pos)
	{
		if (pos < ca)
			return lista[pos];
		return NULL;
	};
};

template <class T1>
inline cLista<T1>::cLista(unsigned int T)
{
	t = T;
	ca = 0;
	try {
		lista = new T1 * [T];
	}
	catch (...) {
		cerr << "Error generico" << endl;
	}
	for (int i = 0; i < T; i++)
	{
		lista[i] = NULL;
	}
}



template <class T1>
inline cLista<T1>::~cLista(void)
{
	try {
		if (lista != NULL) {
			for (int i = 0; i < ca; i++)
			{
				if (lista[i] != NULL)
					delete lista[i];
			}
			delete[]lista;
		}
	}
	catch (exception* e) {
		throw e;
	}

}


template <class T1>
inline void cLista<T1>::Insertar(T1* P)
{
	if (ca < t)
		lista[ca++] = P;
	else throw new exception("No se pueden agregar mas elementos a la lista");
}

template <class T1>
inline void cLista<T1>::Switch(unsigned int pos1, unsigned int pos2) {
	T1* aux = NULL;
	if (pos1 > t || pos2 > t)
		throw new exception("Posicion/es invalida/s");
	aux = lista[pos1];
	lista[pos1] = lista[pos2];
	lista[ca] = NULL;
	return aux;
}

template <class T1>
inline T1* cLista<T1>::Quitar(unsigned int pos) {
	unsigned int i = BuscarAtPos(lista[pos]);
	if (i >= ca)return NULL;
	T1* aux = NULL;
	aux = lista[i];
	ca--;
	for (unsigned int j = i; j < ca; j++)
	{
		lista[j] = lista[j + 1];

	}
	lista[ca] = NULL;
	return aux;
}


template <class T1>
inline T1* cLista<T1>::QuitarPos(unsigned int pos) {

	if (pos >= ca)return NULL;
	T1* aux = NULL;
	aux = lista[pos];
	ca--;
	for (unsigned int j = pos; j < ca; j++)
	{
		lista[j] = lista[j + 1];
	}
	lista[ca] = NULL;
	return aux;
}

template <class T1>
inline void cLista<T1>::Eliminar(int pos)
{
	T1* aux = Quitar(pos);
	if (aux != NULL)
		delete aux;
	else throw new exception("No se pudo eliminar");
}


template <class T1>
inline void cLista<T1>::EliminarenPos(T1* P)
{
	int pos = this->t;
	if (pos >= ca)return;
	delete lista[pos];
	ca--;
	for (int j = pos; j < ca; j++)
	{
		lista[j] = lista[j + 1];
	}
	lista[ca] = NULL;
	return;
}

template <class T1>
inline int cLista<T1>::BuscarAtPos(T1* pos)
{
	for (int i = 0; i < ca; i++)
	{
		if (lista[i] == pos)
			return i;
	}
	return -1;
}



template <class T1>
inline T1* cLista<T1>::Buscar(int pos)
{

	if (pos < ca)
		return lista[pos];

	return NULL;
}


template <class T1>
ostream& operator << (ostream& out, cLista<T1>& Lista)
{
	for (int i = 0; i < Lista.ca; i++)
	{
		out << Lista.lista[i]->to_string() << endl;
	}
	return out;
}

