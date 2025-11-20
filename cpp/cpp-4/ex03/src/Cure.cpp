#include "Cure.hpp"


Cure::Cure(/* args */)
	: AMateria("cure")
{
	all::logs(BLUE "Cure constructor called" RESET);
}

Cure::Cure(
	const Cure &_other
)
	: AMateria(_other._type)
{
	all::logs(BLUE "Cure copy constructor called" RESET);
}


Cure::~Cure()
{
	all::logs(RED "Cure destructor called" RESET);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(
	ICharacter &target
)
{
	out("* heals " << target.getName() << "'s wounds *\n")
}