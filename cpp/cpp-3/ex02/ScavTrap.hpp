#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		/* data */
	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &_other);
		~ScavTrap();

		void	attack(void);
		void	guardGate(void);
		bool	canGuard(void);

		ScavTrap	&operator=(const ScavTrap &_other);
};
