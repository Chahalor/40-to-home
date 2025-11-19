#include "WrongDog.hpp"

WrongDog::WrongDog(/* args */)
{
	this->_type = "Wrong Dog";
}

WrongDog::~WrongDog()
{
}

void	WrongDog::makeSound(void) const
{
	out(ITALIC "wrong dog sound\n" RESET);
}

std::string	WrongDog::getType(void) const
{
	return (this->_type);
}

WrongDog	&WrongDog::operator=(
	const WrongDog &_other
)
{
	this->_type = _other._type;
	return (*this);
}
