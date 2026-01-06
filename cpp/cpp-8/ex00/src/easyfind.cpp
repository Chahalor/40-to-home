#include "easyfind.hpp"

const char	*NotFoundExeption::what() const throw()
{
	return ("target not found");
}
