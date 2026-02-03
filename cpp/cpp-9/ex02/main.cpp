#include <errno.h>

#include "PmergeMe.hpp"

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

	out(YELLOW "Before" RESET ": ");
	_i = 1;
	while (_i < argc)
	{
		char	*_end;
		uint	_value;

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
			out(argv[_i] << " ")	// TODO: dgrader de couleurs
		}
		_i++;
	}

	try
	{
		// TODO: delta time
		PMergeMe<std::deque>(_deque);
		PMergeMe<std::vector>(_vector);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << "\n" RESET;
	}

	return (EXIT_SUCCESS);
}
