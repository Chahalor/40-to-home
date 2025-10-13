#include <iostream>
#include "Fixed.hpp"

#define PART(title) std::cout << YELLOW << title << RESET << "\n";

int main( void )
{
	{
		PART("Subject tests");
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	{
		PART("Additions And Soustractions");
		const float	_a = 4.55f;
		const float	_b = 2.658f;
		Fixed		a(_a);
		Fixed		b(_b);

		std::cout << a + b << " | " << _a + _b << "\n";
		std::cout << b + b << " | " << _b + _b << "\n";
		std::cout << a + 0 << " | " << _a + 0 << "\n";
		std::cout << a - b << " | " << _a - _b << "\n";
	}

	{
		PART("Mult And Divisions");
		const float	_a = 4.55f;
		const float	_b = 2.658f;
		Fixed		a(_a);
		Fixed		b(_b);

		std::cout << a * b << " | " << _a * _b << "\n";
		std::cout << b * b << " | " << _b * _b << "\n";
		std::cout << a * 0 << " | " << _a * 0 << "\n";
		std::cout << a / b << " | " << _a / _b << "\n";
		std::cout << b / a << " | " << _b / _a << "\n";
	}

	{
		PART("Min And Max");
		const float	_a = 4.55f;
		const float	_b = 2.658f;
		Fixed		a(_a);
		Fixed		b(_b);

		std::cout << Fixed::max(a, b) << " | " << std::max(_a, _b) << "\n";
		std::cout << Fixed::max(b, b) << " | " << std::max(_b, _b) << "\n";
		std::cout << Fixed::max(a, 0) << " | " << std::max(_a, 0.0f) << "\n";
		std::cout << Fixed::max(a, b) << " | " << std::max(_a, _b) << "\n";
	}
	return 0;
}