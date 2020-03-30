
#include "Controller.h"

Controller::Controller()
{
	this->r1 = new RepoFile<Produs>("Input.txt");
}

Controller::~Controller()
{
	delete this->r1;
	this->r1 = NULL;
}
void Controller::addProdus(Produs* p) {
	this->r1->addItem(p);
}
void Controller::buyProdus(int cod, int sumaIntrodusa) {
	this->r1->buyItem(cod, sumaIntrodusa);
}
vector<Produs> Controller::getAll() {
	return this->r1->getAll();
}