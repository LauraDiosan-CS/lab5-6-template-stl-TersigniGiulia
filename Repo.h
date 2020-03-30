#pragma once
#include <vector>
#include <iostream>
#include <cmath> 
#include "Monezi.h"
using namespace std;

template<class T> class Repo
{
protected:
	vector<T> itemList;
	Monezi cincizeci, zece;
	T findItemByCod(int cod) {
		for (unsigned int i = 0; i < this->itemList.size(); i++) {
			if (this->itemList[i].getCod() == cod) {
				return this->itemList[i];
				break;
			}
		}
		return T();
	}
	int calcNumarMonezi(double suma, double valoareMoneda) {
		return (int)(suma / valoareMoneda);
	}
public:

	Repo()
	{
		cincizeci = Monezi(0.5, 30);
		zece = Monezi(0.1, 100);
	}
	~Repo()
	{
		this->itemList.~vector();
	}

	void addItem(T* item) {
		this->itemList.push_back(*item);
	}
	void buyItem(int cod, int insertedMoney) {
		int nr_monezi_cincizeci = 0;
		int nr_monezi_zece = 0;
		int disp_50 = -1;
		int disp_10 = -1;
		T item = findItemByCod(cod);

		double rest = insertedMoney - item.getPret();
		if (rest < 0) {
			cout << "Nu s-au introdus suficienti bani. Incearca din nou :)\n";
			return;
		}

		nr_monezi_cincizeci = calcNumarMonezi(rest, 0.5);
		disp_50 = cincizeci.getNumar() - nr_monezi_cincizeci;

		if (disp_50 < 0) {
			nr_monezi_zece += nr_monezi_cincizeci * 5;
		}
		else {
			cincizeci.setNumar(cincizeci.getNumar() - nr_monezi_cincizeci);
		}

		if (rest - nr_monezi_cincizeci * 0.5 > 0)
		{
			nr_monezi_zece += calcNumarMonezi(rest - nr_monezi_cincizeci * 0.5, 0.1);
			disp_10 = zece.getNumar() - nr_monezi_zece;
			if (disp_10 < 0) {
				cout << "Ne pare rau :( Aparatul nu poate da restul corespunzator\n";
				return;
			}
			else {
				zece.setNumar(zece.getNumar() - nr_monezi_cincizeci);
			}
		}
		if (disp_50 >= 0 && disp_10 >= 0) {
			cout << ":)\n Aparatul iti va da rest " << nr_monezi_cincizeci << " monezi de 50 bani si " << nr_monezi_zece << " monezi de 10 bani.\n";
		}
		else if (disp_50 >= 0 && disp_10 < 0) {
			cout << "Aparatul da rest " << nr_monezi_cincizeci << " monezi de 50 bani.\n";
		}
		else if (disp_10 >= 0 && disp_50 < 0) {
			cout << "Aparatul da rest " << nr_monezi_zece << " monezi de 10 bani.\n";
		}
	}
	vector<T> getAll() {
		return this->itemList;
	}
	int getSize() {
		return this->itemList.size();
	}
};