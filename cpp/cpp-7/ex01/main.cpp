#include <cstdlib>
#include <time.h>

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


int	main(void)
{
	int		_dummy;
	int		*_arrayInt = new int[100];
	long	*_arrayLong = new long[100];
	float	*_arrayFloat = new float[100];

	srand(time(NULL) + reinterpret_cast<long>(&_dummy));

	iter<int>(_arrayInt, 100, setRand);
	iter<long>(_arrayLong, 100, setRand);
	iter<float>(_arrayFloat, 100, setRand);

	outl("int | long | float")
	int	_i = 0;
	while (_i < 100)
	{
		outl(_arrayInt[_i] << " " << _arrayLong[_i] << " " << _arrayFloat[_i]);
		_i++;
	}

	delete[] _arrayInt;
	delete[] _arrayLong;
	delete[] _arrayFloat;

	return (EXIT_SUCCESS);
}
