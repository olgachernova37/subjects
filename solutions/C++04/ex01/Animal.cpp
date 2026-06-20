#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}
