#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
	:	_stack(new T[MUTANT_STACK_ALLOC_SIZE]()),
		_capacity(MUTANT_STACK_ALLOC_SIZE),
		_nb_elt(0)
{

}

template<typename T>
MutantStack<T>::MutantStack(
	const MutantStack &_other
)
	:	_stack(new T[_other._capacity]),
		_capacity(_other._capacity),
		_nb_elt(_other._nb_elt)
{
	int	_i;

	_i = 0;
	while (_i < _nb_elt)
	{
		this->_stack[_i] = _other._stack[_i];
		_i++;
	}
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	delete[] this->_stack;
}

template<typename T>
const T	&MutantStack<T>::top(void) const
{
	return (this->_stack[0]);
}

template<typename T>
T	&MutantStack<T>::top(void)
{
	return (this->_stack[0]);
}

template<typename T>
bool	MutantStack<T>::empty(void) const
{
	return (this->_nb_elt == 0);
}

template<typename T>
size_t	MutantStack<T>::size(void) const
{
	return (this->_nb_elt);
}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(
	const MutantStack &_other
)
{
	if (unlikely(this == &_other))
		return (*this);

	T		*_new = new T[_other._capacity];
	size_t	_i;

	_i = 0;
	while (_i < _other->_nb_elt)
	{
		_new[_i] = _other._stack[_i];
		_i++;
	}

	delete[] this->_stack;
	this->_stack = _new;
	this->_capacity = _other._capacity;
	this->_nb_elt = _other._nb_elt;

	return (*this);
}

template<typename T>
void	MutantStack<T>::push(
	const T &_value
)
{
	if (unlikely(this->_nb_elt + 1 >= this->_capacity))
	{
		T		*_new = new T[this->_capacity * 2];
		size_t	_i;

		_i = 0;
		while (_i < this->_nb_elt)
		{
			_new[_i] = this->_stack[_i];
			_i++;
		}

		delete[] this->_stack;
		this->_stack = _new;
		this->_capacity *= 2;
	}

	this->_stack[this->_nb_elt] = _value;
	this->_nb_elt++;
}

template<typename T>
void	MutantStack<T>::pop(void)
{
	this->_nb_elt--;
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->_stack);
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->_stack + this->_nb_elt);
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return (this->_stack);
}
template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return (this->_stack + this->_nb_elt);
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin() const
{
	return (this->_stack);
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend() const
{
	return (this->_stack + this->_nb_elt);
}