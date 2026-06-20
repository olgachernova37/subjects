#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main(void) {
	std::cout << "=== Test 1: subject main ===" << std::endl;

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << "=== Test 2: full inventory + overflow ===" << std::endl;

	ICharacter *hero = new Character("hero");
	hero->equip(new Ice());
	hero->equip(new Cure());
	hero->equip(new Ice());
	hero->equip(new Cure());
	hero->equip(new Ice());

	ICharacter *dummy = new Character("dummy");
	hero->use(0, *dummy);
	hero->use(1, *dummy);
	hero->use(2, *dummy);
	hero->use(3, *dummy);

	delete dummy;
	delete hero;

	std::cout << std::endl << "=== Test 3: unequip then use ===" << std::endl;

	ICharacter *alice = new Character("alice");
	alice->equip(new Ice());
	alice->equip(new Cure());

	ICharacter *target = new Character("target");
	alice->use(0, *target);
	alice->unequip(0);
	alice->use(0, *target);

	delete target;
	delete alice;

	std::cout << std::endl << "=== Test 4: deep copy of Character ===" << std::endl;

	IMateriaSource *src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());

	ICharacter *c1 = new Character("c1");
	c1->equip(src2->createMateria("ice"));
	c1->equip(src2->createMateria("cure"));

	ICharacter *c2 = new Character(*static_cast<Character *>(c1));

	ICharacter *tgt = new Character("tgt");
	std::cout << "c1 uses: ";
	c1->use(0, *tgt);
	std::cout << "c2 uses: ";
	c2->use(0, *tgt);

	delete tgt;
	delete c1;
	delete c2;
	delete src2;

	std::cout << std::endl << "=== Test 5: unknown materia type ===" << std::endl;

	IMateriaSource *src3 = new MateriaSource();
	src3->learnMateria(new Ice());
	AMateria *unknown = src3->createMateria("fire");
	if (!unknown)
		std::cout << "createMateria(\"fire\") returned 0 as expected" << std::endl;
	delete src3;

	return 0;
}
