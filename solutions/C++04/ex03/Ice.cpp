#include "Ice.hpp"
#include <iostream>

// Pass "ice" to AMateria constructor to set _type.
Ice::Ice() : AMateria("ice") {}

// Delegate copy to AMateria's copy constructor (copies _type).
Ice::Ice(Ice const &other) : AMateria(other) {}

// Delegate assignment to AMateria's operator= (does NOT copy _type per subject).
Ice &Ice::operator=(Ice const &other) {
	AMateria::operator=(other);
	return *this;
}

Ice::~Ice() {}

// Prototype pattern: allocates a new Ice that is a copy of *this.
// The caller owns the returned pointer and must delete it.
AMateria *Ice::clone() const {
	return new Ice(*this);
}

// The actual effect: print the ice bolt message.
// target.getName() fetches the name through the ICharacter interface.
void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
