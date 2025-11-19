#pragma once

#include <iostream>

#include "all.hpp"

class Brain
{
private:
public:
	std::string	_idea[100];
	int			_nbIdea;

	Brain(/* args */);
	Brain(const Brain &_other);
	~Brain();

	void	addIdea(std::string &_idea);

	virtual Brain	&operator=(const Brain &_other);
};
