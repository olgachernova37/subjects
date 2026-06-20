#include "Character.hpp"
#include <iostream>

// Initialise name and set all inventory pointers to NULL.
Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

// Deep copy constructor.
// Step 1: zero-initialise inventory so no garbage pointers exist.
// Step 2: clone every non-null materia from the other character.
// Each slot gets a brand-new independent object via clone().
Character::Character(Character const &other) : ICharacter(), _name(other._name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
}

// Deep copy assignment operator.
// Guard against self-assignment: (a = a) would delete then clone from deleted data.
// Delete existing materias first to avoid memory leaks, then clone from other.
Character &Character::operator=(Character const &other) {
	if (this != &other) {
		_name = other._name;
		// Delete old materias to avoid memory leaks before overwriting.
		for (int i = 0; i < 4; i++) {
			delete _inventory[i];
			_inventory[i] = 0;
		}
		// Clone new independent materias from the other character.
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

// Destructor: must delete all materias still in the inventory
// to prevent memory leaks. Deleting a NULL pointer is safe in C++.
Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

std::string const &Character::getName() const {
	return _name;
}

// Equip: scan from slot 0 to 3 and place m in the first NULL slot.
// If all 4 slots are occupied, do nothing — do NOT delete m, caller keeps it.
void Character::equip(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return;
		}
	}
}

// Unequip: set the slot to NULL without deleting the materia.
// The caller must save the pointer before calling unequip if they want it later.
void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return;
	_inventory[idx] = 0;
}

// Use: bounds-check idx, verify the slot is not empty, then delegate to materia.
// The virtual dispatch inside use() ensures the correct Ice or Cure effect runs.
void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		return;
	if (!_inventory[idx])
		return;
	_inventory[idx]->use(target);
}
