#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

// Forward declaration: AMateria is defined elsewhere.
// We only need the pointer here, so we don't include the full header.
class AMateria;

// ICharacter is a pure interface (all methods = 0).
// It defines the contract every character must fulfill.
// No object of ICharacter can be created directly.
class ICharacter {
public:
	// Virtual destructor ensures correct cleanup when
	// a derived object is deleted through an ICharacter pointer.
	virtual ~ICharacter() {}

	// Returns the character's name (read-only).
	virtual std::string const &getName() const = 0;

	// Adds a materia to the first available inventory slot (0-3).
	virtual void equip(AMateria *m) = 0;

	// Removes the materia at slot idx WITHOUT deleting it.
	// Caller is responsible for freeing the memory.
	virtual void unequip(int idx) = 0;

	// Uses the materia at slot idx on the target character.
	virtual void use(int idx, ICharacter &target) = 0;
};

#endif
