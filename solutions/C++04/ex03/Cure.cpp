#include "Cure.hpp"
#include <iostream>

// Pass "cure" to AMateria constructor to set _type.
Cure::Cure() : AMateria("cure") {}

// Delegate copy to AMateria's copy constructor (copies _type).
Cure::Cure(Cure const &other) : AMateria(other) {}

// Delegate assignment to AMateria's operator= (does NOT copy _type per subject).
Cure &Cure::operator=(Cure const &other) {
	AMateria::operator=(other);
	return *this;
}

Cure::~Cure() {}

// Prototype pattern: allocates a new Cure that is a copy of *this.
// The caller owns the returned pointer and must delete it.
AMateria *Cure::clone() const {
	return new Cure(*this);
}

// The actual effect: print the healing message.
void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
