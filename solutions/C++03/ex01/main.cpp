#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap clapTrap("ClapTrap1");
	clapTrap.attack("Enemy");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);
	std::cout << "--------------------------------" << std::endl;
	{
		ScavTrap scavTrap("ScavTrap1");
		scavTrap.attack("Enemy");
		scavTrap.takeDamage(20);
		scavTrap.beRepaired(15);
		scavTrap.guardGate();
	}
	std::cout << "--------------------------------" << std::endl;
	ScavTrap scavTrap2("ScavTrap2");
	scavTrap2.attack("Enemy");
	scavTrap2.guardGate();
	ClapTrap clapTrap2("ClapTrap2");
	clapTrap2.attack("Enemy");
	clapTrap2.takeDamage(10);
	clapTrap2.beRepaired(5);
	std::cout << "--------------------------------" << std::endl;
	return 0;
}
