#include <cstring>

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	// std::memset(this->_memory, static_cast<int>(sizeof(void *)), MEMORY_SIZE);
	int	_i = 0;

	while (_i < MEMORY_SIZE)
		this->_memory[_i++] = NULL;
	all::logs(BLUE "MateriaSource constructor called" RESET);
}

MateriaSource::~MateriaSource()
{
	int	_i = 0;

	while (_i < MEMORY_SIZE)
	{
		if (this->_memory[_i])
		{
			delete this->_memory[_i];
			this->_memory[_i] = NULL;
		}
		_i++;
	}
	all::logs(RED "MateriaSource destructor called" RESET);
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
	return (NULL);
}

void	MateriaSource::learnMateria(
	AMateria *_target
)
{
	static int	_idx = 0;
	int			_i = 0;

	while (_i < MEMORY_SIZE)
	{
		if (!this->_memory[_i])
		{
			this->_memory[_i] = _target;
			_target = NULL;
			return ;
		}
		_i++;
	}

	delete this->_memory[_idx];
	this->_memory[_idx] = _target;
	_idx = (_idx + 1) % MEMORY_SIZE;
}
