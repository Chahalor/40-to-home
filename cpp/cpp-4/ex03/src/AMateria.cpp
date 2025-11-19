#include "all.hpp"
#include "AMateria.hpp"

AMateria::AMateria(
	const std::string &type
)
	: _type(type)
{
	all::logs(BLUE "AMateria constructor called\n" RESET);
}

AMateria::~AMateria()
{
	all::logs(RED "AMateria destructor called\n" RESET);
}

const std::string	&AMateria::getType(void) const
{
	return (this->_type);
}
