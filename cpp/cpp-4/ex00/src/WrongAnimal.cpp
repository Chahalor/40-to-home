#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
}

WrongAnimal::WrongAnimal(
	const std::string &type
)
	:	_type(type)
{

}

WrongAnimal::WrongAnimal(
	const WrongAnimal &other
)
	:	_type(other._type)
{

}


WrongAnimal::~WrongAnimal()
{
}

void	WrongAnimal::makeSound(void) const
{
	out(BOLD "wrong animal sound\n" RESET)
}

std::string	WrongAnimal::getType(void) const
{
	return ("Wwrong animal type\n");
}

WrongAnimal	&WrongAnimal::operator=(
	const WrongAnimal &_other
)
{
	this->_type = _other._type;
	return (*this);
}
