#include "AAnimal.hpp"

AAnimal::AAnimal() : type("") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other) : type(other.type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return type;
}
