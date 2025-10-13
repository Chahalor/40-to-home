#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		/* data */
	public:
		ScavTrap(const std::string name);
		~ScavTrap();

		void	guardGate(void);
		bool	canGuard(void);
};
