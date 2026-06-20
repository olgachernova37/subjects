#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
}

Brain::Brain(Brain const &other) {
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(Brain const &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain() {}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100)
		return "";
	return _ideas[index];
}

void Brain::setIdea(int index, std::string const &idea) {
	if (index < 0 || index >= 100)
		return;
	_ideas[index] = idea;
}
