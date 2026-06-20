#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

// Cure is a concrete materia. Type is always "cure".
class Cure : public AMateria {
public:
	Cure();
	Cure(Cure const &other);
	Cure &operator=(Cure const &other);
	~Cure();

	// Returns a heap-allocated copy of this Cure materia (Prototype pattern).
	AMateria *clone() const;

	// Prints the healing message using the target's name.
	void use(ICharacter &target);
};

#endif
