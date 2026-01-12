#include <cstdlib>
#include <time.h>
#include <iomanip>

#include "all.hpp"
#include "iter.hpp"

#define PART(title) do {outl(YELLOW BOLD UNDERLINE << title << RESET)} while (0);

void	setRand(
	int *const _val
)
{
	*_val = rand();
}

void	setRand(
	float *const _val
)
{
	*_val = rand();
}

void	setRand(
	long *const _val
)
{
	*_val = rand();
}


int	main(const int argc, const char *argv[])
{
	int		_nb_elt = 100;

	if (argc > 2)
	{
		std::cerr << "usage: " << argv[0] << " <nb iter>" << std::endl;
		return (EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		_nb_elt = std::atoi(argv[1]);
		if (unlikely(!_nb_elt))
		{
			std::cerr << "nb iter should be a valid int > 0" << std::endl;
			return (EXIT_FAILURE);
		}
	}

	int		_dummy;
	int		*_arrayInt = new int[_nb_elt]();
	long	*_arrayLong = new long[_nb_elt]();
	float	*_arrayFloat = new float[_nb_elt]();

	srand(time(NULL) + reinterpret_cast<long>(&_dummy));

	iter<int>(_arrayInt, _nb_elt, setRand);
	iter<long>(_arrayLong, _nb_elt, setRand);
	iter<float>(_arrayFloat, _nb_elt, setRand);

	outl(BLUE "   int    " RESET "|" GREEN "      long     " RESET "|" YELLOW "      float" RESET)
	int	_i = 0;
	while (_i < _nb_elt)
	{
		outl(
			BLUE   << std::string(10, '-') << RESET
				<< "+"
			GREEN  << std::string(15, '-') << RESET
				<< "+"
			YELLOW << std::string(20, '-') << RESET
		);
		outl(
			BLUE   << std::setw(10) << _arrayInt[_i]   << RESET
				<< "|"
			GREEN  << std::setw(15) << _arrayLong[_i]  << RESET
				<< "|"
			YELLOW << std::setw(20) << _arrayFloat[_i] << RESET
		);
		// outl(_arrayInt[_i] << " " << _arrayLong[_i] << " " << _arrayFloat[_i]);
		// outl(
		// 	BLUE << std::setw(10) << _arrayInt[_i] << " " RESET
		// GREEN << std::setw(15) << _arrayLong[_i] << " " RESET
		// YELLOW << std::setw(20) << _arrayFloat[_i] << RESET
		// );
		_i++;
	}

	delete[] _arrayInt;
	delete[] _arrayLong;
	delete[] _arrayFloat;

	return (EXIT_SUCCESS);
}
