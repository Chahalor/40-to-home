#include "PmergeMe.hpp"

static void	_do_pairs(
	std::deque<long> &_array,
	std::deque<std::tuple<long, long> >	&_pairs
)
{
	long	_val1;
	long	_val2;

	for (std::deque<long>::iterator _it; _it != _array.end();)
	{
		std::tuple<long, long>	_this;

		_val1 = *(_it++);
		_pairs.pop_back();
		_val2 = *(_it++);
		_pairs.pop_back();

		if (_val1 < _val2)
			_this = {_val1, _val2};
		else
			_this = {_val2, _val1};
	}
}

void	test_deque(
	std::deque<long> &_deque
)
{
	time_t								_start = time(NULL);
	std::deque<std::tuple<long, long> >	_pairs;
	std::deque<long>					_result;

	_do_pairs(_deque, _pairs);

	std::deque<std::tuple<long, long> >::iterator	_it;
	for (std::deque<std::tuple<long, long> >::iterator	_it; _it != _pairs.end();)
	{
		_deque.push_back(_it);
	}
	

}