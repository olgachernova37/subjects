#include "AMateria.hpp"
#include <iostream>

// Initialise _type with the given string via initialiser list.
AMateria::AMateria(std::string const &type) : _type(type) {}

// Copy constructor: the new materia gets the same type as the original.
AMateria::AMateria(AMateria const &other) : _type(other._type) {}

// Assignment operator: the subject says type must NOT be copied on assignment.
// We suppress the warning about the unused parameter with (void)other.
AMateria &AMateria::operator=(AMateria const &other) {
	(void)other;
	return *this;
}

AMateria::~AMateria() {}

// Getter: returns a const reference so the caller cannot modify _type.
std::string const &AMateria::getType() const {
	return _type;
}

// Default use() does nothing — concrete classes override this.
void AMateria::use(ICharacter &target) {
	(void)target;
}
