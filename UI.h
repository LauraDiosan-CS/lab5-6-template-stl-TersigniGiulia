#pragma once
#include "Controller.h"
class UI
{
private:
	Controller* c;
public:
	UI();
	~UI();
	void run();
	void printMeniu();
	void addProdus();
	void buyProdus();
	void getAll();
};