#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::~Weapon(){}

		const std::string& Weapon::getType() const
		{
			return type;
		}
		void Weapon::setType(const std::string newType)
		{
			type = newType;
		}

		void Weapon::announce()
		{
			std::cout << "Weapon type: " << type << std::endl;
		}

