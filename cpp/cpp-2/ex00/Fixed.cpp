#include "Fixed.hpp"

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(const int raw)
{
	this->_fixedPointValue = raw;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (likely(this != &other))
		this->_fixedPointValue = other._fixedPointValue;
	return (*this);
}

Fixed::Fixed(/* args */)
{
	this->_fixedPointValue = 0;
}

Fixed::~Fixed()
{
}
