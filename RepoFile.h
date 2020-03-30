#pragma once
#include "Repo.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using namespace std;
template <class T>
class RepoFile : public Repo<T>
{
private:
	ifstream in;
	ofstream of;
	string fileName;
public:
	RepoFile() : Repo<T>() {};
	RepoFile(string fileName) {
		this->fileName = fileName;
		in.open(fileName);
		if (!in) {
			cerr << "The file could not be open!" << endl;
		}
		addElement();
	}
	~RepoFile() {
		in.close();
		of.close();
	};
	void setFileName(string fileName) {
		this->fileName = fileName;
		in.open(fileName);
		if (!in) {
			cerr << "The file could not be open!" << endl;
		}
	}
	const RepoFile<T>& operator=(const RepoFile<T>& r) {
		this->in = r.in;
		this->fileName = r.fileName;
		return *this;
	}
	void addElement() {
		T el;
		while (in >> el) {
			Repo<T>::addItem(&el);
		}
	}
};