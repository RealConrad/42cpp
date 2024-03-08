#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp); // idx 0
	tmp = src->createMateria("cure");
	me->equip(tmp); // idx 1
	tmp = src->createMateria("ice");
	me->equip(tmp); // idx 2
	tmp = src->createMateria("cure");
	me->equip(tmp); // idx 3
	tmp = src->createMateria("ice");
	me->equip(tmp); // idx 4 - will fail

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(10, *bob); // invalid index
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(10); // invalid index

	delete bob;
	delete me;
	delete src;

	return 0;
}
