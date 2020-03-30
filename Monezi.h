#pragma once
#include <iostream>
using namespace std;
class Monezi
{
private:
	double valoare;
	int numar;
public:
	Monezi();
	Monezi(double valoare, int numar);
	~Monezi();
	double getValoare();
	int getNumar();
	void setNumar(int numar);
	void setValoare(double valoare);
	friend ostream& operator<<(ostream& os, Monezi& c);
	friend istream& operator>>(istream& is, Monezi& c);
};