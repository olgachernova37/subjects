#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie{
	private:
		std::string _name;

	public:
		    Zombie();  // конструктор
    		~Zombie();                  // деструктор
    	void announce();
		void setname (std::string _name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
