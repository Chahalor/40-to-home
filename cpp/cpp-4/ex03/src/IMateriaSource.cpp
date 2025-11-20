#include "IMateriaSource.hpp"

IMateriaSource::~IMateriaSource(void)
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
	all::logs(RED "IMateriaSource destructor called" RESET);
}
void	IMateriaSource::learnMateria(
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
			break ;
		}
		_i++;
	}
	if (_i == MEMORY_SIZE && _target == NULL)
		return ;
	else
	{
		this->_memory[_idx] = _target;
		_idx = (_idx + 1) % MEMORY_SIZE;
	}
}
