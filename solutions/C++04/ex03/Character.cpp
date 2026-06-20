#include "Character.hpp"

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(Character const &other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = 0;
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
}

Character &Character::operator=(Character const &other) {
	if (this != &other) {
		_name = other._name;
		clearInventory();
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character() {
	clearInventory();
}

void Character::clearInventory() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = 0;
	}
}

std::string const &Character::getName() const {
	return _name;
}

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

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}
