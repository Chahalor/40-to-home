#include "HumanB.hpp"

HumanB::HumanB(
	std::string name,
	Weapon *weapon
)
	: _name(name), _weapon(weapon)
{
}

HumanB::HumanB(
	std::string name
)
	: _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks but hes unarmed (it may hurt a bit)" << std::endl;
}

void	HumanB::setWeapon(
	Weapon &weapon
)
{
	this->_weapon = &weapon;
}