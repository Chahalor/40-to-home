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
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal(void);
		virtual ~WrongAnimal();

		void				makeSound(void) const;

		virtual std::string	getType(void) const;

		virtual WrongAnimal	&operator=(const WrongAnimal &_other);
};
