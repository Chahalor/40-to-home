#include <errno.h>
#include <sys/time.h>

#include "PmergeMe.hpp"

__attribute_maybe_unused__
static inline bool	_is_sorted(
	const std::deque<uint> &_input
)
{
	uint	_last;

	_last = *_input.begin();
	for (std::deque<uint>::const_iterator	_it = ++_input.begin();
		_it != _input.end();
		_it++
	)
	{
		if (*_it < _last)
			return (false);
	}

	return (true);
}


__attribute_maybe_unused__
static inline bool	_is_sorted(
	const std::vector<uint> &_input
)
{
	uint	_last;

	_last = *_input.begin();
	for (std::vector<uint>::const_iterator	_it = ++_input.begin();
		_it != _input.end();
		_it++
	)
	{
		if (*_it < _last)
			return (false);
	}

	return (true);
}

int	main(const int argc, const char *argv[])
{
	std::deque<uint>	_deque;
	std::vector<uint>	_vector;
	int					_i;

	if (unlikely(argc < 2))
	{
		std::cerr << "usage: " << argv[0] << " list" << std::endl;
		return (EXIT_FAILURE);
	}

	_i = 1;
	while (_i < argc)
	{
		char	*_end;
		uint	_value;

		if (unlikely(!std::isdigit(argv[_i][0])))
		{
			std::cerr << RED "Error" RESET ": invalid number: '" << argv[_i] <<"'" << std::endl;
			return (EINVAL);
		}
		_value = strtol(argv[_i], &_end, 10);
		if (unlikely(*_end != '\0'))
		{
			std::cerr << RED "Error" RESET ": invalid number: '" << argv[_i] <<"'" << std::endl;
			return (EINVAL);
		}
		else
		{
			_deque.push_back(_value);
			_vector.push_back(_value);
		}
		_i++;
	}

	// TODO: delta time
	try
	{
		print_array(UNDERLINE "unsorted:\n" RESET, _vector);
		outl("=============| " UNDERLINE "DURATIONS" RESET " |==================")

		clock_t	_start_deque = clock();
		std::deque<uint>	deque_result = PMergeMe(_deque);
		clock_t	_end_deque = clock();
		print_duration(_start_deque, _end_deque, "deque", deque_result.size());

		clock_t	_start_vect = clock();
		std::vector<uint>	vector_result = PMergeMe(_vector);
		clock_t	_end_vect = clock();
		print_duration(_start_vect, _end_vect, "vect", vector_result.size());

		outl("=============| " UNDERLINE "STD" RESET " |========================")

		_start_deque = clock();
		std::sort(_deque.begin(), _deque.end());
		_end_deque = clock();
		print_duration(_start_deque, _end_deque, "deque", deque_result.size());

		_start_vect = clock();
		std::sort(_vector.begin(), _vector.end());
		_end_vect = clock();
		print_duration(_start_vect, _end_vect, "vect", vector_result.size());

		outl("============================================")
		// print_array(UNDERLINE "sorted:\n" RESET, vector_result);

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << "\n" RESET;
	}

	return (EXIT_SUCCESS);
}
