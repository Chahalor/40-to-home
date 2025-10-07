#include "Weapon.hpp"

Weapon::Weapon(void)
{

}

Weapon::Weapon(std::string name)
{
	this->_type = name;
}

Weapon::~Weapon()
{

}

std::string	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(
	std::string name
)
{
	this->_type = name;
}
