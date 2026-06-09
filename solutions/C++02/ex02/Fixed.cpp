#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) {
	_value = roundf(value * (1 << _fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(Fixed const &other) {
	if (this != &other)
		_value = other._value;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

bool Fixed::operator>(Fixed const &other) const {
	return _value > other._value;
}

bool Fixed::operator<(Fixed const &other) const {
	return _value < other._value;
}

bool Fixed::operator>=(Fixed const &other) const {
	return _value >= other._value;
}

bool Fixed::operator<=(Fixed const &other) const {
	return _value <= other._value;
}

bool Fixed::operator==(Fixed const &other) const {
	return _value == other._value;
}

bool Fixed::operator!=(Fixed const &other) const {
	return _value != other._value;
}

Fixed Fixed::operator+(Fixed const &other) const {
	Fixed result;
	result._value = _value + other._value;
	return result;
}

Fixed Fixed::operator-(Fixed const &other) const {
	Fixed result;
	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*(Fixed const &other) const {
	Fixed result;
	result._value = (static_cast<long>(_value) * other._value) >> _fractionalBits;
	return result;
}

Fixed Fixed::operator/(Fixed const &other) const {
	Fixed result;
	result._value = (static_cast<long>(_value) << _fractionalBits) / other._value;
	return result;
}

Fixed &Fixed::operator++(void) {
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_value += 1;
	return temp;
}

Fixed &Fixed::operator--(void) {
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_value -= 1;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a._value <= b._value) ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	return (a._value <= b._value) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a._value >= b._value) ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	return (a._value >= b._value) ? a : b;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return out;
}
