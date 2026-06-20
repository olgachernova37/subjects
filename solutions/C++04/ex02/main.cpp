#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
	std::cout << "=== Test 1: subject main ===" << std::endl;

	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();

	delete j;
	delete i;

	std::cout << std::endl << "=== Test 2: Dog deep copy ===" << std::endl;

	Dog basic;
	Dog tmp = basic;

	basic.getBrain()->setIdea(0, "I am hungry");
	tmp.getBrain()->setIdea(0, "I am sleepy");

	std::cout << "basic idea: " << basic.getBrain()->getIdea(0) << std::endl;
	std::cout << "tmp idea:   " << tmp.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "=== Test 3: Cat deep copy ===" << std::endl;

	Cat cat1;
	Cat cat2 = cat1;

	cat1.getBrain()->setIdea(0, "Catch the mouse");
	cat2.getBrain()->setIdea(0, "Sleep in the sun");

	std::cout << "cat1 idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "cat2 idea: " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "=== Test 4: Dog assignment ===" << std::endl;

	Dog dogA;
	Dog dogB;

	dogA.getBrain()->setIdea(0, "Run in the park");
	dogB = dogA;
	dogB.getBrain()->setIdea(0, "Dig a hole");

	std::cout << "dogA idea: " << dogA.getBrain()->getIdea(0) << std::endl;
	std::cout << "dogB idea: " << dogB.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "=== Test 5: AAnimal array (half Dog, half Cat) ===" << std::endl;

	const int size = 6;
	AAnimal *zoo[size];

	for (int n = 0; n < size / 2; n++)
		zoo[n] = new Dog();
	for (int n = size / 2; n < size; n++)
		zoo[n] = new Cat();

	for (int n = 0; n < size; n++) {
		std::cout << zoo[n]->getType() << ": ";
		zoo[n]->makeSound();
	}

	for (int n = 0; n < size; n++)
		delete zoo[n];

	std::cout << std::endl << "=== Test 6: stack objects via AAnimal pointer ===" << std::endl;

	Dog stackDog;
	Cat stackCat;

	const AAnimal *ptrDog = &stackDog;
	const AAnimal *ptrCat = &stackCat;

	std::cout << ptrDog->getType() << ": ";
	ptrDog->makeSound();
	std::cout << ptrCat->getType() << ": ";
	ptrCat->makeSound();

	return 0;
}
