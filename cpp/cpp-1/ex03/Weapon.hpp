#pragma once

#include <iostream>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string _name);
		~Weapon();

		const std::string	&getType(void);

		void				setType(std::string _name);
};
