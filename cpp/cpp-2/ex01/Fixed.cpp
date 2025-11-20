#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
	: _fixedPointValue(0)
{
}

Fixed::Fixed(
	const int value
)
	: _fixedPointValue(value << _fractionalBits)
{
}

Fixed::Fixed(
	const float value
)
	: _fixedPointValue((float)roundf((float)value * (1 << _fractionalBits)))
{
}

Fixed::Fixed(
	const Fixed &_other
)
{
	this->_fixedPointValue = _other._fixedPointValue;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(
	const Fixed &other
)
{
	if (likely(this != &other))
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(
	std::ostream &os,
	const Fixed &f
)
{
	os << f.toFloat();
	return os;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(
	const int raw
)
{
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}
