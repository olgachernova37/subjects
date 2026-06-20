#include "Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain()) {
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow murr murr" << std::endl;
}

Brain *Cat::getBrain() {
	return _brain;
}

Brain const *Cat::getBrain() const {
	return _brain;
}
