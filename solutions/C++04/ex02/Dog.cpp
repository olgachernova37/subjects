#include "Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain()) {
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof woof woof" << std::endl;
}

Brain *Dog::getBrain() {
	return _brain;
}

Brain const *Dog::getBrain() const {
	return _brain;
}
