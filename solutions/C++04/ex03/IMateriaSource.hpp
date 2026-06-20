#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

// Forward declaration: we only need the pointer type here.
class AMateria;

// IMateriaSource is a pure interface for a materia factory.
// It can store up to 4 materia templates and produce clones on demand.
class IMateriaSource {
public:
	virtual ~IMateriaSource() {}

	// Stores a clone of the given materia as a template.
	// The source takes ownership of m and deletes the original.
	virtual void learnMateria(AMateria *) = 0;

	// Creates and returns a new materia whose type matches the given string.
	// Returns 0 (NULL) if the type is unknown.
	// Caller is responsible for deleting the returned materia.
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
