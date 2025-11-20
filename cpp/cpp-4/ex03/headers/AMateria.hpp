#pragma once

#include <iostream>

#include "all.hpp"
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(const std::string &type);
		AMateria(const AMateria &_other);
		virtual ~AMateria();

		const std::string	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter& target);

		AMateria			&operator=(const AMateria &_other);
};
