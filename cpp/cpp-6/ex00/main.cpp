#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <exception>
#include <iostream>

#include "ScalarConverter.hpp"

int	main(const int argc, const char *argv[])
{
	std::string input;

	if (argc != 2)
	{
		std::cerr << "usage: " << argv[0] << ": <number>" << std::endl;
		return (EXIT_FAILURE);
	}

	input = argv[1];
	ScalarConverter::convert(input);
	return (EXIT_SUCCESS);
}
