#pragma once

#include <iostream>

#include "all.hpp"

class WrongAnimal
{
	private:
		;

	protected:
		static std::string	_type;

	public:
		WrongAnimal(const std::string &type);
		WrongAnimal(void);
		~WrongAnimal();

		void	makeSound(void) const;

		std::string	getType(void) const;
};
