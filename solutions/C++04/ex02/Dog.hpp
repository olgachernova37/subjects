#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
	Brain *_brain;

public:
	Dog();
	Dog(Dog const &other);
	Dog &operator=(Dog const &other);
	~Dog();
	void makeSound() const;
	Brain *getBrain();
	Brain const *getBrain() const;
};

#endif
