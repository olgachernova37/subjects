#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

// AMateria is an abstract base class for all materia types.
// It cannot be instantiated directly because clone() is pure virtual.
class AMateria {
protected:
	// The materia type identifier, e.g. "ice" or "cure".
	std::string _type;

public:
	// Stores the type string in _type.
	AMateria(std::string const &type);

	// Copy constructor: copies _type from the other materia.
	AMateria(AMateria const &other);

	// Assignment operator intentionally does NOT copy _type.
	// Subject says: "while assigning a Materia, copying the type doesn't make sense."
	AMateria &operator=(AMateria const &other);

	// Virtual destructor — needed so derived class destructors are called
	// correctly when deleting through an AMateria pointer.
	virtual ~AMateria();

	// Returns the materia type string (const reference, no copy).
	std::string const &getType() const;

	// Pure virtual: each concrete materia must return a new copy of itself.
	// This is the Prototype design pattern.
	virtual AMateria *clone() const = 0;

	// Base implementation does nothing. Overridden in Ice and Cure.
	virtual void use(ICharacter &target);
};

#endif
