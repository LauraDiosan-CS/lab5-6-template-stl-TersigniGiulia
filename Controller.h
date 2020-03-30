#pragma once
#include "RepoFile.h"
#include "Produs.h"
class Controller
{
private:
	RepoFile<Produs>* r1;
public:
	Controller();
	~Controller();
	void addProdus(Produs* p);
	void buyProdus(int cod, int sumaIntrodusa);
	vector<Produs> getAll();

};