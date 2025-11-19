#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	all::logs(BLUE "MateriaSource constructor called\n" RESET);
}

MateriaSource::~MateriaSource()
{
	all::logs(BLUE "MateriaSource destructor called\n" RESET);
}

AMateria	*MateriaSource::createMateria(
	const std::string &_type
)
{
	int	_i = 0;

	while (_i < MEMORY_SIZE)
	{
		if (this->_memory[_i] && _type == this->_memory[_i]->getType())
			return (this->_memory[_i]->clone());
		_i++;
	}
	return (nullptr);
}

void		MateriaSource::learMateria(AMateria *_target)
{
	
}