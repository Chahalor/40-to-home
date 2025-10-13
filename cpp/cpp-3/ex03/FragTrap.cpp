#include "FragTrap.hpp"

FragTrap::FragTrap(
	const std::string name
)
	: ClapTrap(name)
{
	this->_hp = 100;
	this->_mp = 100;
	this->_dmg = 30;

	out(name << ", the Fragtrap is constructed\n")
}

FragTrap::~FragTrap()
{
	out(this->_name << ", the Fragtrap is destroyed\n")
}

void	FragTrap::highFivesGuy(void)
{
	out("[" YELLOW << std::time(NULL) << RESET "]" BLUE << this->_name << RESET ": let's do an high fives guy\n")
}