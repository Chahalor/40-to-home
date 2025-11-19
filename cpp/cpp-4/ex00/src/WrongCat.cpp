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
	out(ITALIC "wrong" RESET " meow meow\n");
}

std::string	WrongCat::getType(void) const
{
	return (this->_type);
}

WrongCat	&WrongCat::operator=(
	const WrongCat &_other
)
{
	this->_type = _other._type;
	return (*this);
}
