#include "all.hpp"

#include <algorithm>
#include <limits.h>

std::string	all::itoa(
	int _value
)
{
	std::string	result;
	long long	_val;
	bool		_neg;

	if (_value == 0)
		return ("0");

	_val = _value;
	_neg = (_val < 0);
	if (_neg)
		_val = -_val;

	while (_val)
	{
		result += static_cast<char>(_val % 10 + '0');
		_val /= 10;
	}
	if (_neg)
		result += '-';
	std::reverse(result.begin(), result.end());
	return (result);
}
