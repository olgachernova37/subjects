#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(Point const &other) {
	if (this != &other) {
		this->~Point();
		new (this) Point(other);
	}
	return *this;
}

Point::~Point() {}

Fixed Point::getX(void) const {
	return _x;
}

Fixed Point::getY(void) const {
	return _y;
}
