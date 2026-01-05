#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <random>
#include <time.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define PART(title) do {outl(YELLOW BOLD UNDERLINE << title << RESET)} while (0);


Base	*generate(void)
{
	int	_rand = random();

	switch (_rand % 3)
	{
		case (0):
			return (new A);
		case (1):
			return (new B);
		case (2):
		default:
			return (new C);
	}
}

void	identify(
	Base* p
)
{
	if (dynamic_cast<A *>(p))
		out(GREEN "A" RESET)
	else if (dynamic_cast<B *>(p))
		out(YELLOW "B" RESET)
	else if ((dynamic_cast<C *>(p)))
		out(BLUE "C" RESET)
	else
		out(RED "unknown type" RESET)
}

void	identify(
	Base& p
)
{
	identify(&p);
}

int	main(const int argc, const char *argv[])
{

	int	_nb_iterations = 100;
	int	_dummy;

	if (argc == 2)
	{
		_nb_iterations = std::atoi(argv[1]);
		if (_nb_iterations < 1)
		{
			std::cerr << "nb Bases should be a valid unsigned int" << std::endl;
			return (EXIT_FAILURE);
		}
	}
	else if (argc > 2)
	{
		std::cerr << "usage: " << argv[0] << " <nb Bases>" << std::endl;
		return (EXIT_FAILURE);
	}

	srand(time(NULL) + (reinterpret_cast<size_t>(&_dummy)));

	PART("just bob")

	Base	*bob = generate();

	identify(bob);
	outl("");
	delete bob;

	PART(_nb_iterations << " boby pointer")

	int	_i = 0;
	while (_i++ < _nb_iterations)
	{
		Base	*boby = generate();
		identify(boby);
		out(" ");
		delete boby;
	}

	PART("\n" << _nb_iterations <<" boby ref")

	_i = 0;
	while (_i++ < _nb_iterations)
	{
		Base	*boby = generate();
		identify(*boby);
		out(" ");
		delete boby;
	}

	return (EXIT_SUCCESS);

}
