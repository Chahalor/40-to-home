#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap(const std::string name);
		~DiamondTrap();
	
		void	attack(const std::string &target);
		void	whoAmI(void);
};

std::ostream	&operator<<(std::ostream &os, const DiamondTrap &d);
