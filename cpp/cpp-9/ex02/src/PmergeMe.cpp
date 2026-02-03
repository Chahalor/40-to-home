#include "PmergeMe.hpp"

/**
 *			{0						if n == 0;
 * J(n) =	{1						if n == 1;
 *			{J(n - 1) + 2J(n - 2);	if n > 1;
 */
// uint	_jacobsthal(
// 	uint _n
// )
// {
// 	uint	_a = 0;
// 	uint	_b = 1;
// 	uint	_c;

// 	if (_n == 0)
// 		return (0);
// 	else if (_n == 1)
// 		return (1);

// 	for (uint	_i = 2;
// 		_i <= _n;
// 		++_i
// 	)
// 	{
// 		_c = _b + 2 * _a;
// 		_a = _b;
// 		_b = _c;
// 	}
// 	return (_b);
// }
