#include "Fixed.hpp"
#include <cmath>

/* ************************************************************************** */
/*                                 Constructors                               */
/* ************************************************************************** */

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
	: _fixedPointValue(_other._fixedPointValue)
{

}

/* ************************************************************************** */
/*                                 Destructors                                */
/* ************************************************************************** */


Fixed::~Fixed()
{
}

/* ************************************************************************** */
/*                                 Operators                                  */
/* ************************************************************************** */

Fixed& Fixed::operator=(
	const Fixed &other
)
{
	if (likely(this != &other))
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

bool Fixed::operator>(
	const Fixed &other
)
{
	return (other._fixedPointValue > this->_fixedPointValue
			? true
			: false
		);
}

bool Fixed::operator<(
	const Fixed &other
)
{
	return (other._fixedPointValue < this->_fixedPointValue
			? true
			: false
		);
}

bool Fixed::operator>=(
	const Fixed &other
)
{
	return (other._fixedPointValue >= this->_fixedPointValue
			? true
			: false
		);
}

bool Fixed::operator<=(
	const Fixed &other
)
{
	return (other._fixedPointValue <= this->_fixedPointValue
			? true
			: false
		);
}

bool Fixed::operator==(
	const Fixed &other
)
{
	return (other.getRawBits() == this->getRawBits()
			? true
			: false
		);
}

bool Fixed::operator!=(
	const Fixed &other
)
{
	return (other.getRawBits() != this->getRawBits()
			? true
			: false
		);
}

Fixed	Fixed::operator+(
	const Fixed &other
)
{
	Fixed	res;
	res.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return (res);
	// this->_fixedPointValue += other._fixedPointValue;
	// return (*this);
}

Fixed	Fixed::operator-(
	const Fixed &other
)
{
	Fixed	res;

	res.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return (res);
	// this->_fixedPointValue -= other._fixedPointValue;
	// return (*this);
}

Fixed	Fixed::operator*(
	const Fixed &other
)
{
	Fixed	res;
	res.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
	return (res);
	// this->_fixedPointValue = (this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits;
	// return (*this);
}

Fixed	Fixed::operator/(
	const Fixed &other
)
{
	Fixed	res;
	res.setRawBits((this->_fixedPointValue << _fractionalBits) / other._fixedPointValue);
	return (res);
	// _fixedPointValue = (this->_fixedPointValue << _fractionalBits) / other._fixedPointValue;
	// return (*this);
}

Fixed	Fixed::operator++(
	int value
)
{
	(void)value;
	Fixed	dummy = *this;

	this->_fixedPointValue += 1;
	return (dummy);
}

Fixed	Fixed::operator--(
	int value
)
{
	(void)value;
	Fixed	dummy = *this;

	this->_fixedPointValue -= 1;
	return (dummy);
}

Fixed	Fixed::operator++(void)
{
	this->_fixedPointValue += 1;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->_fixedPointValue -= 1;
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

/* ************************************************************************** */
/*                                 getter                                     */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                                 To                                         */
/* ************************************************************************** */

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}


/* ************************************************************************** */
/*                                 Comparisions                               */
/* ************************************************************************** */

Fixed	&Fixed::min(
	Fixed &f1,
	Fixed &f2
)
{
	return (f1.getRawBits() >= f2.getRawBits()
			? f2
			: f1
		);
}

Fixed	&Fixed::max(
	Fixed &f1,
	Fixed &f2
)
{
	return (f1.getRawBits() >= f2.getRawBits()
			? f1
			: f2
		);
}

Fixed	const& Fixed::min(
	Fixed const& f1,
	Fixed const& f2
)
{
	return (f1.getRawBits() >= f2.getRawBits()
			? f2
			: f1
		);
}

Fixed	const& Fixed::max(
	Fixed const& f1,
	Fixed const& f2
)
{
	return (f1.getRawBits() >= f2.getRawBits()
			? f1
			: f2
		);
}
