#pragma once

#include <iostream>

#include "all.hpp"

class Animal
{
	private:
		;

	protected:
		static std::string	_type;

	public:
		Animal(const std::string &type);
		Animal(void);
		~Animal();

		void	makeSound(void) const;

		std::string	getType(void) const;
};
