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

		virtual void		makeSound(void) const = 0;

		virtual std::string	getType(void) const;

		virtual Animal		&operator=(const Animal &_other);
};
