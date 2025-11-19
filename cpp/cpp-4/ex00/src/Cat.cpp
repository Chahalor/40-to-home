#include "Cat.hpp"

Cat::Cat(/* args */)
{
	this->_type = "Cat";
}

Cat::~Cat()
{
}

void	Cat::makeSound(void) const
{
	out("Meow meow\n");
}

std::string	Cat::getType(void) const
{
	return (this->_type);
}

Cat	&Cat::operator=(
	const Cat &_other
)
{
	this->_type = _other._type;
	return (*this);
}
