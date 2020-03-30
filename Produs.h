#pragma once
#include <string>
using namespace std;
class Produs
{
private:
	string nume;
	int cod;
	double pret;
public:
	Produs();
	Produs(string nume, int cod, double pret);
	Produs(const Produs& prod);
	Produs& operator=(const Produs& prod);
	~Produs();
	void setNume(string nume);
	void setCod(int cod);
	void setPret(double pret);

	string getNume();
	int getCod();
	double getPret();

	friend ostream& operator<<(ostream& os, Produs& c);
	friend istream& operator>>(istream& is, Produs& c);
};