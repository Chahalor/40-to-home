#include "Weapon.hpp"

Weapon::Weapon(std::string _name)
{
	this->_type = _name;
}

Weapon::~Weapon()
{

}

const std::string	&Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(
	std::string _name
)
{
	this->_type = _name;
}
