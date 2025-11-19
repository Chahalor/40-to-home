#include "Brain.hpp"


Brain::Brain(/* args */)
	: _nbIdea(0)
{
	outl(BLUE "Brain constructor called" RESET)
}

Brain::Brain(
	const Brain &_other
)
{
	int	_i = 0;

	while (_i < _other._nbIdea)
	{
		this->_idea[_i] = std::string(_other._idea[_i]);
		_i++;
	}
	this->_nbIdea = _other._nbIdea;
}

Brain::~Brain()
{
	outl(RED "Brain destructor called" RESET)
}

void	Brain::addIdea(
	std::string &_idea
)
{
	static int	_i = 0;

	if (this->_nbIdea < 100)
		this->_idea[this->_nbIdea++] = _idea;
	else
	{
		this->_idea[_i] = _idea;
		_i = (_i + 1) % 100;
	}
}

Brain &Brain::operator=(
	const Brain &_other
)
{
	int	_i = 0;

	if (unlikely(this == &_other))
		return (*this);
	
	this->_nbIdea = _other._nbIdea;
	
	while (_i < _other._nbIdea)
	{
		this->_idea[_i] = _other._idea[_i];
		_i++;
	}
	
	return (*this);
}
