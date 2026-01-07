#include "RPN.hpp"

int	main(const int argc, const char *argv[])
{
	if (unlikely(argc != 2))
	{
		std::cerr << "usage: " << argv[0] << " \"expresion\"" << std::endl;
		return (EXIT_FAILURE);
	}

	try
	{
		outl(RPN::evaluate(argv[1]));
		return (EXIT_SUCCESS);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}
	
}
