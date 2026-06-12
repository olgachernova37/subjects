#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clapTrap("ClapTrap1");
	clapTrap.attack("Enemy");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);
	std::cout << "--------------------------------" << std::endl;
	ClapTrap clapTrap2("ClapTrap2");
	clapTrap2.attack("Enemy");
	clapTrap2.takeDamage(10);
	clapTrap2.beRepaired(5);
	std::cout << "--------------------------------" << std::endl;
	return 0;
}
