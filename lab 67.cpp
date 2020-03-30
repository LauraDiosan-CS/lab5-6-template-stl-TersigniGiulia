#include <iostream>
#include "TesteProdus.h"
#include "TesteRepo.h"
#include "UI.h"
#include "RepoFile.h"
using namespace std;
int main()
{

	TesteProdus tp;
	tp.run();
	TesteRepo tr;
	tr.run();
	UI ui;
	ui.run();

}