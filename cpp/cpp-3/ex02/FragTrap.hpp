#pragma once

#include <ctime>

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
		/* data */
	public:
		FragTrap(const std::string name);
		~FragTrap();

		void	attack(const std::string &target);
		void	highFivesGuy(void);
};
