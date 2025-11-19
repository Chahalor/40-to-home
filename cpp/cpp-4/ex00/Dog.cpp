#include "Dog.hpp"

Dog::Dog(/* args */)
{
	this->_type = "Dog";
}

Dog::~Dog()
{
}

void	Dog::makeSound(void) const
{
	out("Woof Woof\n")
}

std::string	Dog::getType(void) const
{
	return (this->_type);
}
