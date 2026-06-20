#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

// Ice is a concrete materia. Type is always "ice".
class Ice : public AMateria {
public:
	Ice();
	Ice(Ice const &other);
	Ice &operator=(Ice const &other);
	~Ice();

	// Returns a heap-allocated copy of this Ice materia (Prototype pattern).
	AMateria *clone() const;

	// Prints the ice-bolt attack message using the target's name.
	void use(ICharacter &target);
};

#endif
