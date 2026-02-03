#include "PmergeMe.hpp"


template<template<typename> class C>
C<uint>	_build_insert_order(
	const uint _size
)
{
	uint	_val;
	uint	_last;
	uint	_start;
	uint	_current = 1;
	C<uint>	result;

	_val = _jacobsthal(_current);
	_last = 0;
	while (_current < _size)
	{
		_start = _val;
		while (_val > _last)
		{
			result.push_back(_val--);
		}
		_last = _start;
		_current++;
	}

	return (result);
}

template<template<typename> class C>
void	_do_pairs(
	C<s_pair> &_pairs,
	C<uint> &_input
)
{
	while (_input.size())
	{
		uint	_val1;
		uint	_val2;

		_val1 = _input.front();
		_input.pop_front();
		_val2 = _input.front();
		_input.pop_front();

		s_pair	_pair = s_pair(_val1, _val2);
		_pairs.push_back(_pair);
	}
}

template<template<typename> class C>
C<uint>	_extract_max(
	C<s_pair> &_pairs
)
{
	size_t	_i;
	C<uint>	result;

	_i = 0;
	while (_i < _pairs.size())
	{
		result.push_back(_pairs.at(_i));
		_i++;
	}

	return (result);
}

template<template<typename> class C>
C<uint>	_insert(
	C<s_pair> &_min,
	C<uint> &_max
)
{
	C<uint>	_jack;
	C<uint>	result = _max;

	_jack = _build_insert_order(_min.size());

	for (uint	_pos = _jack.front();
		_jack.size();
		_pos = _jack.front()
	)
	{
		typename C<uint>::iterator	_pos_max = std::lower_bound(_max.begin(), _max.end(), _min.at(_pos).big);

		result.insert(_pos_max, _min.at(_pos).small);

		_jack.pop_front();
	}

	return (result);
}

template<template<typename> class C>
void _bin_insert(
	const long _left_over,
	C<uint> &_maximus
)
{
	typename C<uint>::iterator	_pos = std::lower_bound(_maximus.begin(), _maximus.end(), _left_over);

	_maximus.insert(_pos, static_cast<uint>(_left_over));
}

template<template<typename> class C>
C<uint>	PMergeMe(
	C<uint> _input
)
{
	C<s_pair>	_pairs;
	long		_left_over = -1;
	C<uint >		maximus;

	if (_input.size() < 3)
		return (_input);
	else if (_input.size() % 2)
	{
		_left_over = _input.back();
		_input.pop_back();
	}

	_do_pairs(_pairs, _input);

	maximus = extract_max(_pairs);

	maximus = PMergeMe(maximus);

	_insert(_pairs, maximus);

	if (_left_over >= 0)
		_bin_insert(_left_over, maximus);

	return (maximus);
}

// , std::allocator<uint> 