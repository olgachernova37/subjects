#include "HumanB.hpp"


HumanB::HumanB(std::string name): _name(name){

	weapon = NULL;
}
HumanB::~HumanB(){}

void HumanB::attack(){
	std::cout<< _name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& club){

	weapon = &club;
}
