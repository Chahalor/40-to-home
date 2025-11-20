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
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &_other);
		virtual ~Animal();

		virtual void		makeSound(void) const;

		virtual std::string	getType(void) const;

		virtual Animal		&operator=(const Animal &_other);
};
