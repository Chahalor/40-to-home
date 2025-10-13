#include <math.h>

#include "./Fixed.hpp"
#include "Point.hpp"

static inline float sign(
	Point const &p1,
	Point const &p2,
	Point const &p3
)
{
	return ((p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat()) -
			(p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat()));
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &p)
{
	bool b1, b2, b3;

	b1 = sign(p, a, b) < 0.0f;
	b2 = sign(p, b, c) < 0.0f;
	b3 = sign(p, c, a) < 0.0f;

	return ((b1 == b2) && (b2 == b3));
}
