#pragma once

#include <iostream>

#include "all.hpp"
#include "ICharacter.hpp"

class AMateria
{
	protected:
		static std::string	_type;

	public:
		AMateria(const std::string &type);

		const std::string	&getType() const; //Returns the materia type
		virtual AMateria		*clone() const = 0;
		virtual void			use(ICharacter& target);
};
