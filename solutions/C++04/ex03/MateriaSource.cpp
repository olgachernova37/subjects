#include "MateriaSource.hpp"

// Initialise all template slots to NULL.
MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_templates[i] = 0;
}

// Deep copy constructor: clone every non-null template from the other source.
MateriaSource::MateriaSource(MateriaSource const &other) {
	for (int i = 0; i < 4; i++)
		_templates[i] = 0;
	for (int i = 0; i < 4; i++) {
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
	}
}

// Deep copy assignment: delete current templates, then clone from other.
MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete _templates[i];
			_templates[i] = 0;
		}
		for (int i = 0; i < 4; i++) {
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
		}
	}
	return *this;
}

// Destructor: release all stored templates to avoid memory leaks.
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete _templates[i];
}

// learnMateria: we clone m so the source owns its own independent copy.
// The original m is then deleted here — the source takes ownership of the argument.
// If all 4 slots are already filled, m is deleted and silently ignored.
void MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!_templates[i]) {
			_templates[i] = m->clone(); // store our own copy
			delete m;                   // discard the passed-in original
			return;
		}
	}
	delete m; // templates full — delete to avoid leak
}

// createMateria: scan templates for a type match.
// On match, return a fresh clone — the caller must delete it.
// Return 0 if no matching template is found (unknown type).
AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return 0;
}
