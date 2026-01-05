#include "all.hpp"

#include <limits.h>

std::string	all::itoa(
	int _value
)
{
	std::string	result;

	while (_value)
	{
		result += _value % 10 + '0';
		_value /= 10;
	}
	return (result);
}
