#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                                 Constructors                               */
/* ************************************************************************** */

ClapTrap::ClapTrap(
	const std::string name
)
	: _name(name), _hp(10), _mp(10), _dmg(0)
{
	out("ClapTrap constructed with name '" << name << "'\n")
}

/* ************************************************************************** */
/*                                 Destructors                                */
/* ************************************************************************** */

ClapTrap::~ClapTrap()
{
	out("ClapTrap '" << this->_name << "' has been destroyed\n")
}

/* ************************************************************************** */
/*                                 Members                                    */
/* ************************************************************************** */

void	ClapTrap::attack(
	const std::string &target
)
{
	if (unlikely(this->_mp <= 0 || this->_hp <= 0))
		return ;
	out("ClapTrap '" << this->_name <<
		"' attacks " << target <<
		", causing "<< this->_dmg <<
		" points of damage!\n"
	);
	this->_mp--;
}

void	ClapTrap::takeDamage(
	unsigned int amount
)
{
	if (this->_hp > 0)
	{
		out("ClapTrap '" << this->_name <<
			"' taked " << amount <<
			" points of damage!\n"
		);
		this->_hp -= amount;
	}
	else
		out("dealing " << amount << " points of damage! to the broken ClapTrap '" << this->_name << "'\n")
}

void	ClapTrap::beRepaired(
	unsigned int amount
)
{
	if (this->_mp <= 0 || this->_hp <= 0)
		return ;
	this->_hp += amount;
	out("ClapTrap '" << this->_name <<
		"' repaired " << amount <<
		" points of damage!\n"
	);
}

void	ClapTrap::setDamage(
	int amount
)
{
	this->_dmg = amount;
}

void	ClapTrap::setMana(
	int amount
)
{
	this->_mp = amount;
}