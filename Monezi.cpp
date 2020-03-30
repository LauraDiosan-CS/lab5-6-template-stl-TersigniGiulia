#include "Monezi.h"
#include <iostream>
using namespace std;

//constr fara parametri
Monezi::Monezi()
{
	this->numar = 0;
	this->valoare = 0;
}

//constructor cu parametri
Monezi::Monezi(double valoare, int numar) {
	this->valoare = valoare;
	this->numar = numar;
}

//Destructor
Monezi::~Monezi() {
}

//getter pentru valoare
double Monezi::getValoare() {
	return this->valoare;
}

//getter pentru numar
int Monezi::getNumar() {
	return this->numar;
}

//setter pentru numar
void Monezi::setNumar(int numar) {
	this->numar = numar;
}

//setter ptr valoare
void Monezi::setValoare(double valoare) {
	this->valoare = valoare;
}


//Suprascriere operator de afisare
ostream& operator<<(ostream& os, Monezi& c) {
	os << c.valoare << " " << c.numar << endl;
	return os;
}

//Suprascriere operator de intrare
istream& operator>>(istream& is, Monezi& c) {
	is >> c.valoare >> c.numar;
	return is;
}