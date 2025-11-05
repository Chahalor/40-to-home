#include "Cat.hpp"

Cat::Cat(/* args */)
{
	this->_type = "Cat";
}

Cat::~Cat()
{
}

void	Cat::Animal::makeSound(void) const
{
	out("Meow meow\n");
}

std::string	Cat::Animal::getType(void) const
{
	return (this->_type);
}
