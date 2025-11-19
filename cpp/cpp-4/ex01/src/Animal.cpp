#include "Animal.hpp"

Animal::Animal(void)
{
}

Animal::~Animal()
{
}

void	Animal::makeSound(void) const
{
	out(ITALIC "strange animal sound\n" RESET)
}

std::string	Animal::getType(void) const
{
	return ("no type, this is an animal\n");
}

Animal	&Animal::operator=(
	const Animal &_other
)
{
	this->_type = _other._type;
	return (*this);
}
