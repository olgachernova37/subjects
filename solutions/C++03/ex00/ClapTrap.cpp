#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructed" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no hit points" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy points" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0)
		return;
	if (amount >= static_cast<unsigned int>(_hitPoints))
		_hitPoints = 0;
	else
		_hitPoints -= static_cast<int>(amount);
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no hit points" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy points" << std::endl;
		return;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount
		<< " points!" << std::endl;
}
