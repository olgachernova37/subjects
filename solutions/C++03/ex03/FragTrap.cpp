#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
   std::cout << "FragTrap wants to high five everyone!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}



// • Name, which is passed as a parameter to the constructor
// • Hit points (100), representing the health of the ClapTrap
// • Energy points (100)
// • Attack damage (30)
// FragTrap has a special ability too:
// void highFivesGuys(void);