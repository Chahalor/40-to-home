#pragma once

#include <ctime>

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	private:
		/* data */
	public:
		FragTrap(const std::string name);
		~FragTrap();

		void	highFivesGuy(void);
};
