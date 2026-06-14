#ifndef  FRAGTRAP_HPP
#define  FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
    FragTrap(std::string name);
    ~FragTrap();
    int _hitPoints;
	int _energyPoints;
	int _attackDamage;
    void highFivesGuys(void);
};

#endif


