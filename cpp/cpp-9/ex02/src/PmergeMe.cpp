#include "PmergeMe.hpp"

/**
 *			{0						if n == 0;
 * J(n) =	{1						if n == 1;
 *			{J(n - 1) + 2J(n - 2);	if n > 1;
 */
static inline size_t	_jacobsthal(
	size_t _n
)
{
	size_t	_a = 0;
	size_t	_b = 1;
	size_t	_c;

	if (_n == 0)
		return (0);
	else if (_n == 1)
		return (1);

	for (size_t	_i = 2;
		_i <= _n;
		++_i
	)
	{
		_c = _b + 2 * _a;
		_a = _b;
		_b = _c;
	}
	return (_b);
}

template<typename T>
size_t	_do_pairs(
	const T &_list,
	s_pair *const _pairs
)
{
	long	_val1;
	long	_val2;
	size_t	_i;

	_i = 0;
	for (typename T::const_iterator	_it = _list.begin();
		_it != _list.end();
	)
	{
		_val1 = *_it++;
		_val2 = *_it++;

		_pairs[_i] = s_pair(_val1, _val2);
		_i++;
	}

	return (_i);
}

template<typename T>
void	_extract_index(
	s_pair *const _pairs,
	const size_t _nb_pairs,
	const size_t _index,
	T &_dest
)
{
	for (size_t	_i = 0;
		_i < _nb_pairs;
		_i++
	)
	{
		_dest.push_back(_pairs[_i][_index]);
	}
}

template<typename T>
T	_insert(
	T &_result,
	T &_minimums
)
{
	size_t	_i;
	T		_jack;

	_i = 1;
	while (_jack.size() < _minimums.size())
	{
		unsigned long	_last = 1;
		unsigned long	_val = _jacobstal(_i);
		unsigned long	_tmp = _val;

		while (_val != _last && _val > 0)
		{
			if (_val < _minimums.size())
				_jack.push_back(_val);
			_val--;
		}
		_last = _tmp;
		_i++;
	}

	_i = 0;
	for (typename T::iterator	_it = _minimums.begin();
		_it != _minimums.end();
		_it++
	)
	{
		_result.at(_jack[_i]) = *_it;
		_i++;
	}

	return (_result);
}

template<typename T>
void	_add_leftover(
	T &_result,
	const long _val
)
{
	long	_last = _result.front();

	for (typename T::iterator	_it = ++_result.begin();
		_it != _result.end();
		_it++
	)
	{
		if ((_val > _last && _val < *_it) || _it + 1 == _result.end())
		{
			_result.insert(_it, _val);
			break ;
		}
		_last = *_it;
	}
}

template<typename T>
T	Sortator2000(
	T &_list
)
{
	s_pair	_pairs[(_list.size() / 2) + 1];
	long	_left_over = -1;
	size_t	_nb_pairs;
	T		_minimums;
	T		_maximus;
	T		result;

	if (_list.size() <= 1)
		return (_list);
	else if (_list.size() % 2)
	{
		_left_over = _list.back();
		_list.pop_back();
	}

	_nb_pairs = _do_pairs(_list, _pairs);

	_extract_index(_pairs, _nb_pairs, 0, _minimums);
	_extract_index(_pairs, _nb_pairs, 1, _maximus);

	result = Sortator2000(_maximus);

	result = _insert(result, _minimums);

	if (_left_over > 0)
		_add_leftover(result, _left_over);

	return (result);
}

template std::deque<long> Sortator2000<std::deque<long> >(std::deque<long> &);
template std::vector<long> Sortator2000<std::vector<long> >(std::vector<long> &);
