#include "UI.h"


UI::UI()
{
	this->c = new Controller();
}


UI::~UI()
{
	delete this->c;
	this->c = NULL;
}

void UI::run() {
	int opt;
	do {
		printMeniu();
		cin >> opt;
		switch (opt) {
		case 1:
		{
			addProdus();
			break;
		}
		case 2:
		{
			buyProdus();
			break;
		}
		case 3:
		{
			getAll();
			break;
		}
		}
	} while (opt != 0);
}
void UI::printMeniu() {
	cout << "Simulare tonomat dulciuri\n";
	cout << "\n";
	cout << "1.Adauga un produs\n";
	cout << "2.Cumpara un produs\n";
	cout << "3.Afiseaza produsele\n";
	cout << "0.Iesire\n";

}
void UI::addProdus() {
	Produs p;
	cout << "Introduceti datele produsului (Cod/Nume/Pret)" << endl;
	cin >> p;
	this->c->addProdus(&p);
}
void UI::buyProdus() {
	int cod;
	int suma;
	cout << "Alegeti produsul (cod) ";
	cin >> cod;
	cout << "Introduceti banii :) ";
	cin >> suma;
	this->c->buyProdus(cod, suma);
}
void UI::getAll() {
	vector<Produs> produse = this->c->getAll();
	cout << "Cod/Nume/Pret" << endl;
	for (unsigned int i = 0; i < produse.size(); i++) {
		cout << produse[i];
	}
}