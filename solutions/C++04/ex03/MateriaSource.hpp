#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

// MateriaSource is the concrete factory implementing IMateriaSource.
// It holds up to 4 materia templates and produces fresh clones on demand.
class MateriaSource : public IMateriaSource {
private:
	// Internal library of learned materia templates (up to 4 slots).
	AMateria *_templates[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &other);
	MateriaSource &operator=(MateriaSource const &other);
	~MateriaSource();

	// Clone m, store the copy in the first free template slot, then delete m.
	// If all 4 slots are full, m is deleted and the call is ignored.
	void learnMateria(AMateria *m);

	// Return a fresh clone of the template whose type matches the argument.
	// Caller owns the returned pointer and must delete it.
	// Returns 0 if no matching template is found.
	AMateria *createMateria(std::string const &type);
};

#endif
