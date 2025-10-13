#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                                 Constructors                               */
/* ************************************************************************** */

ScavTrap::ScavTrap(
	const std::string name
)
	: ClapTrap(name)
{
	this->_hp = 100;
	this->_mp = 50;
	this->_dmg = 20;
	out("ScavTrap with name '" << name << "' is constucted\n")
}

/* ************************************************************************** */
/*                                 Destructors                                */
/* ************************************************************************** */

ScavTrap::~ScavTrap()
{
	out("ScavTrap with name '" << this->_name << "' is destoyed\n")
}

/* ************************************************************************** */
/*                                 Members                                    */
/* ************************************************************************** */

void	ScavTrap::guardGate(void)
{
	if (this->_hp <= 0)
		out("ScavTrap '" << this->_name << "' is broken and can't guard the gate\n")
	else if (this->_mp <= 0)
		out("ScavTrap '" << this->_name << "' is having difficutly guarding the gate\n")
	else
		out("ScavTrap '" << this->_name << "' is guarding the gate\n")
}

bool	ScavTrap::canGuard(void)
{
	return (this->_mp > 0 && this->_hp > 0);
}
