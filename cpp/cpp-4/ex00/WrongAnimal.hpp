#pragma once

#include <iostream>

#include "all.hpp"

class WrongAnimal
{
	private:
		;

	protected:
		std::string	_type;

	public:
		WrongAnimal(const std::string &type);
		WrongAnimal(void);
		virtual ~WrongAnimal();

		virtual void		makeSound(void) const;

		virtual std::string	getType(void) const;
};
