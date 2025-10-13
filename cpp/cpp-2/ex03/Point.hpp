#pragma once

#include <math.h>

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point(void);
		Point(float x, float y);
		Point(const Point &other);
		~Point();

		Point	&operator=(const Point &other);
		bool	operator!=(const Point &other);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

		static Fixed	triangleArea(const Point &p1, const Point &p2, const Point &p3);
};

std::ostream	&operator<<(std::ostream &os, const Point &p);
