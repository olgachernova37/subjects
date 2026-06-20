#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

// Character is the concrete implementation of the ICharacter interface.
// It holds a fixed inventory of 4 materia slots.
class Character : public ICharacter {
private:
	std::string	_name;

	// Inventory of up to 4 materia pointers.
	// Unused slots are set to 0 (NULL).
	AMateria	*_inventory[4];

public:
	// Construct a character with a given name; all inventory slots start empty (NULL).
	Character(std::string const &name);

	// Deep copy constructor: each non-null materia in other's inventory is cloned,
	// so both characters own independent materia objects.
	Character(Character const &other);

	// Deep copy assignment: delete current inventory first, then clone from other.
	Character &operator=(Character const &other);

	// Destructor: delete every materia still held in the inventory.
	~Character();

	std::string const &getName() const;

	// Place m into the first empty slot (0 to 3).
	// Does nothing if the inventory is full or m is NULL.
	void equip(AMateria *m);

	// Remove the materia at slot idx WITHOUT deleting it.
	// The slot is set to NULL; the caller keeps responsibility for the memory.
	void unequip(int idx);

	// Call _inventory[idx]->use(target).
	// Does nothing if idx is out of range or the slot is empty.
	void use(int idx, ICharacter &target);
};

#endif
