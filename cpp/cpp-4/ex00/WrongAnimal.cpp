#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
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
	return ("Wwrong animal type");
}