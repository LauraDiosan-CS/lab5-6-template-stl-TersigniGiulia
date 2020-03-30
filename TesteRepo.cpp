#include "TesteRepo.h"
#include "Repo.h"
#include "Produs.h"
#include <assert.h>
void TesteRepo::test_getSize_isSet() {
	Repo<Produs> r1;
	r1.addItem(new Produs());
	assert(r1.getSize() == 1);

}
void TesteRepo::test_getSize_isNotSet() {
	Repo<Produs> r1;
	r1.addItem(new Produs());
	assert(r1.getSize() != 2);

}
void TesteRepo::run() {
	test_getSize_isSet();
	test_getSize_isNotSet();
}
