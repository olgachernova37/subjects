#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
	Point a;
	Point const b(5.0f, 5.0f);
	Point const c(10.0f, 5.0f);
	Point const d(7.07f, 3.43f);

	bool ret = bsp(a, b, c, d);
	std::cout << ret << std::endl;

	return 0;
}
