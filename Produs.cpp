#include "Produs.h"
#include <string>
#include <iostream>
using namespace std;
Produs::Produs()
{
}
Produs::Produs(string nume, int cod, double pret) {
	this->nume = nume;
	this->cod = cod;
	this->pret = pret;
}
Produs& Produs::operator=(const Produs& prod) {
	this->nume = prod.nume;
	this->cod = prod.cod;
	this->pret = prod.pret;
	return *this;
}
Produs::Produs(const Produs& prod) {
	if (this != &prod) {
		*this = prod;
	}
}
Produs::~Produs()
{}
void Produs::setNume(string nume) {
	this->nume = nume;
}
void Produs::setCod(int cod) {
	this->cod = cod;
}
void Produs::setPret(double pret) {
	this->pret = pret;
}
string Produs::getNume() {
	return this->nume;
}
int Produs::getCod() {
	return this->cod;
}
double Produs::getPret() {
	return this->pret;
}
ostream& operator<<(ostream& os, Produs& c) {
	os << c.cod << " " << c.nume << "  " << c.pret << endl;
	return os;
}

//Suprascriere operator de intrare
istream& operator>>(istream& is, Produs& c) {
	is >> c.cod >> c.nume >> c.pret;
	return is;
}