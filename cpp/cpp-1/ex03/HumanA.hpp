#pragma once

#include <iostream>

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA(std::string _name, Weapon &weapon);
		~HumanA();

		void	attack(void);
};
