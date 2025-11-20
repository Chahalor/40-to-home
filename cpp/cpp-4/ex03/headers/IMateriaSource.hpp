#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
	protected:
		AMateria	*_memory[MEMORY_SIZE];

	public:
		virtual ~IMateriaSource();

		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria	*createMateria(std::string const & type) = 0;

		IMateriaSource		&operator=(const IMateriaSource &_other);
};
