#include "WrongDog.hpp"

WrongDog::WrongDog(/* args */)
{
	this->_type = "Wrong Dog";
}

WrongDog::~WrongDog()
{
}

void	WrongDog::WrongAnimal::makeSound(void) const
{
	out(ITALIC "wrong" RESET "Woof woof");
}

std::string	WrongDog::WrongAnimal::getType(void) const
{
	return (this->_type);
}
