#pragma once

#include <iostream>

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;

	public:
		HumanB(std::string _name, Weapon *weapon);
		HumanB(std::string _name);
		~HumanB();

		void	setWeapon(Weapon &weapon);
		void	attack(void);
};
