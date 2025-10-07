#pragma once

#include <iostream>

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB(std::string name, Weapon *weapon);
		HumanB(std::string name);
		~HumanB();

		void	setWeapon(Weapon &weapon);
		void	attack(void);
};
