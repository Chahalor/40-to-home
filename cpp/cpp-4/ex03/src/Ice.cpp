#include "Ice.hpp"

Ice::Ice(/* args */)
	: AMateria("ice")
{
	all::logs(BLUE "Ice constructor called\n" RESET);
}

Ice::Ice(
	const Ice &_other
)
	: AMateria(_other._type)
{
	all::logs(BLUE "Ice copy constructor called\n" RESET);
}


Ice::~Ice()
{
	all::logs(RED "Ice destructor called\n" RESET);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(
	ICharacter &target
)
{
	out("* shoots an ice bolt at " << target.getName() << " *\n")
}