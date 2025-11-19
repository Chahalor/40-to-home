#include "IMateriaSource.hpp"

IMateriaSource::~IMateriaSource(void)
{
	int	_i = 0;

	while (_i < MEMORY_SIZE)
		delete this->_memory[_i];
	all::logs(RED "IMateriaSource destructor called\n" RESET);
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
			_target = nullptr;
			break ;
		}
		_i++;
	}
	if (_i == MEMORY_SIZE && _target == nullptr)
		return ;
	else
	{
		this->_memory[_idx] = _target;
		_idx = (_idx + 1) % MEMORY_SIZE;
	}
}
