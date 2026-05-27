#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce() {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname (std::string name)
{
	_name = name;
}
