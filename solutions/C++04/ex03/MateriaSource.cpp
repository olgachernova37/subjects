#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_templates[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	for (int i = 0; i < 4; i++) {
		_templates[i] = 0;
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
	}
}

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

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete _templates[i];
		_templates[i] = 0;
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!_templates[i]) {
			_templates[i] = m->clone();
			delete m;
			return;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return 0;
}
