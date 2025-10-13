#include "Point.hpp"

/* ************************************************************************** */
/*                                 Constructors                               */
/* ************************************************************************** */


Point::Point(void)
	: _x(0), _y(0)
{
}

Point::Point(
	float x,
	float y
)
	: _x(x), _y(y)
{

}

Point::Point(
	const Point &other
)
	: _x(other._x), _y(other._y)
{

}

/* ************************************************************************** */
/*                                 Destructors                                */
/* ************************************************************************** */

Point::~Point()
{
}

/* ************************************************************************** */
/*                                 Getter                                     */
/* ************************************************************************** */

Fixed Point::getX(void) const
{
	return (this->_x);
}
Fixed Point::getY(void) const
{
	return (this->_y);
}

/* ************************************************************************** */
/*                                 Operators                                  */
/* ************************************************************************** */

Point &Point::operator=(
	const Point &other
)
{
	(void)other;
	return (*this);
}

bool	Point::operator!=(
	const Point &other
)
{
	return (
		this->_x.getRawBits() != other._x.getRawBits() &&
		this->_y.getRawBits() != other._y.getRawBits()
	);
}

std::ostream& operator<<(
	std::ostream &os,
	const Point &p
)
{
	os << "[" << p.getX() << ", " << p.getY() << "]";
	return (os);
}

/* ************************************************************************** */
/*                                 Statics                                    */
/* ************************************************************************** */

Fixed	Point::triangleArea(
	Point const &p1,
	Point const &p2,
	Point const &p3
)
{
	const Fixed	term1 = p1._x * (p2._y - p3._y);
	const Fixed	term2 = p2._x * (p3._y - p1._y);
	const Fixed	term3 = p3._x * (p1._y - p2._y);
	const Fixed	area = (term1 + term2 + term3) / Fixed(2);

	return Fixed::abs(area);
}

