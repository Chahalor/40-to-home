#include <iostream>

#include "all.hpp"

class ClapTrap
{
	private:
		std::string	_name;
		int			_hp;
		int			_mp;
		int			_dmg;
	public:
		ClapTrap(const std::string name);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	setDamage(int amount);
};
