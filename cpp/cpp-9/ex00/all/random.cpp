#include "all.hpp"

int	all::randint(
	const int _val1,
	const int _val2
)
{
	const int	_val = rand();
	const int	_min = std::min(_val1, _val2);
	const int	_max = std::max(_val1, _val2);

	return (_min + (_val % ((_max - _min) + 1)));
}

size_t	all::randint(
	const size_t _val1,
	const size_t _val2
)
{
	const size_t	_val = rand();
	const size_t	_min = std::min(_val1, _val2);
	const size_t	_max = std::max(_val1, _val2);

	return (_min + (_val % ((_max - _min) + 1)));
}