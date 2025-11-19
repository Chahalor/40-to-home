#pragma once

#include <iostream>

#include "all.hpp"

class Animal
{
	private:
		;

	protected:
		std::string	_type;

	public:
		Animal(const std::string &type);
		Animal(void);
		virtual ~Animal();

		virtual void		makeSound(void) const;

		virtual std::string	getType(void) const = 0;
};
