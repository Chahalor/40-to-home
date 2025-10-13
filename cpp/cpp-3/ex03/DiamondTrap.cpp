#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(
	const std::string name
)
	:	ClapTrap(name + "_clap_name"),
		FragTrap(name),
		ScavTrap(name),
		_name(name)
{
	_hp = 100;
	_mp = 50;
	_dmg = 30;
	out("the Abominous " RED "DiamondTrap " RESET << name << " is created\n")
}

DiamondTrap::~DiamondTrap()
{
	out("the Abominous " RED "DiamondTrap " RESET << this->_name << " is destroyed\n")
}

void	DiamondTrap::attack(
	const std::string &target
)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	out(
		"ClapTrap name: " << ClapTrap::_name << "\n" <<
		"DiamdondTrap name: " << this->_name << "\n"
	);
}