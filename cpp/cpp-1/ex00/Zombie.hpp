#pragma once

#include <iostream>

#include "all.hpp"

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(std::string _name);
		Zombie(void);
		~Zombie();

		void	announce(void);
};

Zombie	*newZombie(
			std::string _name
			);

void	randomChump(
			std::string _name
			);