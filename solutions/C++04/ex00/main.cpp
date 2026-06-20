#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	std::cout << "=== Test 1: subject main (virtual) ===" << std::endl;

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "=== Test 2: array polymorphism ===" << std::endl;

	Animal *animals[4];
	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog();

	for (int n = 0; n < 4; n++) {
		std::cout << animals[n]->getType() << ": ";
		animals[n]->makeSound();
	}

	for (int n = 0; n < 4; n++)
		delete animals[n];

	std::cout << std::endl << "=== Test 3: stack objects via Animal pointer ===" << std::endl;

	Dog stackDog;
	Cat stackCat;

	const Animal *ptrToDog = &stackDog;
	const Animal *ptrToCat = &stackCat;

	std::cout << ptrToDog->getType() << ": ";
	ptrToDog->makeSound();
	std::cout << ptrToCat->getType() << ": ";
	ptrToCat->makeSound();

	std::cout << std::endl << "=== Test 4: WrongAnimal / WrongCat (no virtual) ===" << std::endl;

	const WrongAnimal *wrongMeta = new WrongAnimal();
	WrongCat *heapWrongCat = new WrongCat();
	const WrongAnimal *wrongCat = heapWrongCat;

	std::cout << wrongCat->getType() << std::endl;
	std::cout << wrongMeta->getType() << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete heapWrongCat;

	std::cout << std::endl << "=== Test 5: WrongCat called directly ===" << std::endl;

	WrongCat directWrongCat;
	std::cout << directWrongCat.getType() << ": ";
	directWrongCat.makeSound();

	std::cout << std::endl << "=== Test 6: compare Cat vs WrongCat ===" << std::endl;

	const Animal *goodCat = new Cat();
	WrongCat *heapBadCat = new WrongCat();
	const WrongAnimal *badCat = heapBadCat;

	std::cout << "Cat via Animal*: ";
	goodCat->makeSound();
	std::cout << "WrongCat via WrongAnimal*: ";
	badCat->makeSound();

	delete goodCat;
	delete heapBadCat;

	return 0;
}
