#include "all.hpp"
#include "AMateria.hpp"

AMateria::AMateria(
	const std::string &_type
)
{
	this->_type = _type;
	all::logs(BLUE "AMateria constructor callen" RESET);
}

AMateria::~AMateria()
{
	all::logs(RED "AMateria destructor called" RESET);
}

const std::string	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(
	ICharacter &_target
)
{
	(void)_target;
}