#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */)
{
	this->_type = "Wrong Cat";
}

WrongCat::~WrongCat()
{
}

void	WrongCat::makeSound(void) const
{
	out(ITALIC "wrong" RESET "meow meow");
}

std::string	WrongCat::WrongAnimal::getType(void) const
{
	return (this->_type);
}
