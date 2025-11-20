#pragma once

#include <iostream>

#include "all.hpp"

class ClapTrap
{
	private:
		;

	protected:
		std::string	_name;
		int			_hp;
		int			_mp;
		int			_dmg;

	public:
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &_other);
		~ClapTrap();

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void		setDamage(int amount);

		ClapTrap	&operator=(const ClapTrap &_other);
};
