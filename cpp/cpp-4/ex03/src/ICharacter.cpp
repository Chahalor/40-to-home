#include "all.hpp"
#include "ICharacter.hpp"

// ICharacter::ICharacter(void)
// {
// 	all::logs(BLUE "ICharacter constructor called" RESET);
// }

ICharacter::~ICharacter(void)
{
	all::logs(RED "ICharacter destructor called" RESET);
}
