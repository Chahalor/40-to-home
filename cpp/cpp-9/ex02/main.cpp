#include <errno.h>

#include "PmergeMe.hpp"

int	main(const int argc, const char *argv[])
{
	std::deque<long>	_deque;
	std::vector<long>	_vector;
	int					_i;

	if (unlikely(argc < 2))
	{
		std::cerr << "usage: " << argv[0] << " list" << std::endl;
		return (EXIT_FAILURE);
	}

	out(YELLOW "Before" RESET ": ");
	_i = 1;
	while (_i < argc)
	{
		char	*_end;
		long	_value;

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
			out(argv[_i] << " ")	// TODO: show a "..." if to many elements
		}
		_i++;
	}


	test_deque(_deque);
	test_vector(_vector);
	
	return (EXIT_SUCCESS);
}
