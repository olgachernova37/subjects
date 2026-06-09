#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_value;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const &other);
	Fixed &operator=(Fixed const &other);
	~Fixed();
	int toInt(void) const;
	float toFloat(void) const;


	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif
