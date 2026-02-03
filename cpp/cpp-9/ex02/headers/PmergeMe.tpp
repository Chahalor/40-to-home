#pragma once

#include <vector>
#include <deque>
#include <algorithm>
#include <cstddef>

static inline uint _jacobsthal(
	const uint n
)
{
	uint	_a = 0;
	uint	_b = 1;

	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);

	for (uint	_i = 2;
		_i <= n;
		++_i
	)
	{
		uint	_c = _b + 2 * _a;
		_a = _b;
		_b = _c;
	}

	return (_b);
}

template<template<typename, typename> class C, typename T>
struct _container_of
{
	typedef C<T, std::allocator<T> > type;
};

template<template<typename, typename> class C>
typename _container_of<C, uint>::type	_build_insert_order(
	uint m
)
{
	typedef typename _container_of<C, uint>::type	t_uint_container;
	typedef typename _container_of<C, char>::type	t_char_container;

	t_uint_container	order;

	if (m <= 1)
		return (order);

	t_char_container	_used(m, 0);
	uint				_curr;
	uint				_prev;
	uint				_k;

	order.push_back(1);
	_used[1] = 1;

	_prev = 1;
	_k = 3;
	while (_prev < m - 1)
	{
		_curr = _jacobsthal(_k++);
		if (_curr >= m)
			_curr = m - 1;

		for (
			uint	_i = _curr;
			_i > _prev;
			--_i
		)
		{
			if (!_used[_i])
			{
				order.push_back(_i);
				_used[_i] = 1;
			}
		}
		_prev = _curr;
		if (_curr == m - 1)
			break;
	}

	for (uint	_i = 2;
		_i < m;
		++_i
	)
	{
		if (!_used[_i])
			order.push_back(_i);
	}

	return (order);
}


template<template<typename, typename> class C>
void	_do_pairs(
	typename _container_of<C, s_pair>::type &pairs,
	const typename _container_of<C, uint>::type &input
)
{
	for (std::size_t	_i = 0;
		_i + 1 < input.size();
		_i += 2
	)
	{
		pairs.push_back(s_pair(input[_i], input[_i + 1]));
	}
}

template<template<typename, typename> class C>
typename _container_of<C, uint>::type	_extract_max(
	const typename _container_of<C, s_pair>::type &pairs
)
{
	typedef typename _container_of<C, uint>::type	t_uint_container;

	t_uint_container	maxs;

	for (std::size_t	_i = 0;
		_i < pairs.size();
		++_i
	)
	{
		maxs.push_back(pairs[_i].big);
	}

	return (maxs);
}

template<template<typename, typename> class C>
typename _container_of<C, s_pair>::type	_pairs_in_max_order(
	const typename _container_of<C, s_pair>::type &pairs,
	const typename _container_of<C, uint>::type &sorted_max
)
{
	typedef typename _container_of<C, s_pair>::type pair_container;

	std::vector<char>	_used(pairs.size(), 0);
	pair_container		ordered;

	for (std::size_t	_i = 0;
		_i < sorted_max.size();
		++_i
	)
	{
		uint	_mx = sorted_max[_i];

		for (std::size_t	_j = 0;
			_j < pairs.size();
			++_j
		)
		{
			if (!_used[_j] && pairs[_j].big == _mx)
			{
				ordered.push_back(pairs[_j]);
				_used[_j] = 1;
				break;
			}
		}
	}
	return (ordered);
}

template<typename Cont>
static inline typename Cont::iterator	_find_value_it(
	Cont &c,
	uint v
)
{
	typename Cont::iterator it = std::lower_bound(c.begin(), c.end(), v);

	return (it);
}

template<template<typename, typename> class C>
typename _container_of<C, uint>::type	_insert_minima(
	const typename _container_of<C, s_pair>::type &pairs_ordered,
	const typename _container_of<C, uint>::type &max_sorted
)
{
	typedef typename _container_of<C, uint>::type	t_uint_container;

	uint								_mn;
	uint								_mx;
	typename t_uint_container::iterator	_ub;
	typename t_uint_container::iterator	_pos;
	uint								_idx;
	t_uint_container					_order;
	t_uint_container					result = max_sorted;


	if (pairs_ordered.empty())
		return (result);

	{
		_mn = pairs_ordered[0].small;
		_mx = pairs_ordered[0].big;

		_ub = _find_value_it(result, _mx);
		_pos = std::lower_bound(result.begin(), _ub, _mn);
		result.insert(_pos, _mn);
	}

	_order = _build_insert_order<C>((uint)pairs_ordered.size());

	for (std::size_t	_k = 0;
		_k < _order.size();
		++_k
	)
	{
		_idx = _order[_k];
		if (_idx >= pairs_ordered.size())
			continue;

		_mn = pairs_ordered[_idx].small;
		_mx = pairs_ordered[_idx].big;

		_ub = _find_value_it(result, _mx);
		_pos = std::lower_bound(result.begin(), _ub, _mn);
		result.insert(_pos, _mn);
	}

	return (result);
}

template<template<typename, typename> class C>
void	_bin_insert(
	long left_over,
	typename _container_of<C, uint>::type &sorted
)
{
	uint	_v;

	if (left_over < 0)
		return ;

	_v = static_cast<uint>(left_over);
	typename _container_of<C, uint>::type::iterator	_pos = std::lower_bound(
																			sorted.begin(),
																			sorted.end(),
																			_v
																		);

	sorted.insert(_pos, _v);
}

template<template<typename, typename> class C>
typename _container_of<C, uint>::type	_PMergeMe_impl(
	typename _container_of<C, uint>::type input
)
{
	typedef typename _container_of<C, s_pair>::type	t_pair_container;
	typedef typename _container_of<C, uint>::type	t_uint_container;

	long				_left_over = -1;
	t_pair_container	_pairs;
	t_uint_container	_maxs;
	t_pair_container	_pairs_ordered;
	t_uint_container	_result;

	if (input.size() <= 1)
		return (input);
	else if (input.size() % 2)
	{
		_left_over = input.back();
		input.pop_back();
	}

	_do_pairs<C>(_pairs, input);

	_maxs = _extract_max<C>(_pairs);
	_maxs = _PMergeMe_impl<C>(_maxs);

	_pairs_ordered = _pairs_in_max_order<C>(_pairs, _maxs);

	_result = _insert_minima<C>(_pairs_ordered, _maxs);

	_bin_insert<C>(_left_over, _result);

	return (_result);
}

inline std::vector<uint>	PMergeMe(
	const std::vector<uint> &input
)
{
	return (_PMergeMe_impl<std::vector>(input));
}

inline std::deque<uint>		PMergeMe(
	const std::deque<uint> &input
)
{
	return (_PMergeMe_impl<std::deque>(input));
}
